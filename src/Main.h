// src\Main.h - main code
#pragma once // Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)
#include "Version.h"
#include "Constants.h"
#include "Log.h"
#include "FOutputDeviceStdOutput.h"
#include "StringConvert.h"
#include "CmdLiner.h"
#include "Registry.h"
#include "UeLocator.h"
#include "DelayloadStaticVar.h"
#include "FileSystem.h"
#include "DevTpl.h"

// Didn't find a nice way to avoid using the ugly and 
//	not-so-official Z_Construct_UClass_ prefix.
//	There will also be a call to Z_Construct_UClass_UTemplateProjectDefs
UClass* Z_Construct_UClass_UDefaultTemplateProjectDefs();

namespace prj_3d { namespace UePrjCreator {
struct Main {
static int run(int argc, wchar_t *argv[]) {
	// UePrjCreator options
	std::wstring ProjectFullFilename, UeInstallDir, UeVersion, TemplateFullFilename;
	EGraphicsPreset::Type Performance;
	EHardwareClass::Type Hardware;
	bool bCodeGenerate, bIsBlankTemplate, bTplDev;
	CmdLiner cmdLiner( argc, argv );
	if ( !cmdLiner.parse( 
			ProjectFullFilename
			, UeInstallDir
			, Performance
			, Hardware
			, UeVersion
			, TemplateFullFilename
			, bTplDev
			, bCodeGenerate 
			, bIsBlankTemplate 
			, g_bVerbose
	) )
		return ERROR_BAD_ARGUMENTS;

	if ( bTplDev ) {
		DevTpl &devTpl = DevTpl::Get( );
		if ( !devTpl.CreateTemplateInTemporaryDirectory( ) ) {
			UPC_LOG( L"Error! Cant write to system temporary directory" );
			return ERROR_INVALID_ACCESS;
		}
		UPC_TRACE( "Please, use -OverrideBuildEnvironment argument for UBT" );
		TemplateFullFilename = devTpl.getFullFilename( );
	}

	if ( UeInstallDir.empty( ) ) {
		int exitCode = UeLocator< >::getPreferedDirectory( UeVersion, UeInstallDir );
		if ( ERROR_SUCCESS != exitCode )
			return exitCode;
	} else {
		UPC_TRACE( L"Try load selected path of Unreal Engine: \n  [%s]", UeInstallDir.c_str( ) );
	}
	UeInstallDir += LR"(\Engine\Binaries\Win64)";

	// Need for delayload-ing UnrealEngine dlls
	if ( !::SetCurrentDirectoryW( UeInstallDir.c_str( ) ) ) { 
		int gle = (int)GetLastError( );
		UPC_LOG( L"Error! Cant set directory\n  [%s]\n  GetLastError() = %d", UeInstallDir.c_str( ), gle );
		return gle;
	}

	UPC_TRACE( "Start load ue core lib..." );
	DWORD StartTick = ::GetTickCount( );

	// Get mangled static imported symbols, no import static direct
	ELogTimes::Type *pGPrintLogTimes;
	FOutputDeviceError **pGError;
	FFeedbackContext **pGWarn;
	FSimpleMulticastDelegate *pOnInit;
	bool bDelayloadStaticVar = DelayloadStaticVar::GetAddressBySymbol::UE4Editor_Core( 
		pGPrintLogTimes, pGError, pGWarn, pOnInit );
	if ( !bDelayloadStaticVar ) {
		UPC_LOG( "Error! Cant find some symbols in Unreal Engine core" );
		return ERROR_PRODUCT_VERSION;
	}

	// Prepare Ue minimal environment
	FString CmdLineForUe = argv[ 0 ];
	CmdLineForUe.Append( Constants::getUnrealEngineCommandLine( ) );
	GLog ->SetCurrentThreadAsMasterThread( );
	FCommandLine::Set( *CmdLineForUe );
	*pGPrintLogTimes = ELogTimes::Type::Local; // show timestamps in log
	FOutputDeviceStdOutput OutputDeviceStdOutput( pGPrintLogTimes );
	if ( g_bVerbose ) 
		GLog ->AddOutputDevice( &OutputDeviceStdOutput );
	*pGError = FPlatformApplicationMisc::GetErrorOutputDevice( );
	*pGWarn = FPlatformApplicationMisc::GetFeedbackContext( );
	UPC_TRACE( L"Core loaded in %d milliseconds, run creation..."
			, ( ::GetTickCount( ) - StartTick ) 
		);

	FConfigCacheIni::InitializeConfigSystem( );
	// Take from delayload to load and pre-init static UObject-s
	::LoadLibraryA( "UE4Editor-GameProjectGeneration.dll" ); // leak
	// Prepare initializer UObject-s
	if ( !FModuleManager::Get( ).LoadModule( L"CoreUObject" ) )
		UPC_LOG( "Fail load and startup UE4Editor-CoreUObject.dll" );
	// Init loaded UObject-s. Fill indepth ThreadHash for use UObject-s
	pOnInit ->Broadcast( );
	// Prepare Unreal Engine project generator in GameProjectUtils
	if ( !FModuleManager::Get( ).LoadModule( L"GameProjectGeneration" ) )
		UPC_LOG( "Fail load and startup UE4Editor-GameProjectGeneration.dll" );

	// Init static StaticEnum<EHardwareClass::Type> for GameProjectUtils
	CreatePackage( L"/Script/HardwareTargeting" );

	// For GameProjectUtils::AddSharedContentToProject need AddContentDialog
	//		AddContentDialog call FFeaturePackContentSource::ParseManifestString for 
	//		each Template directory and inside parse FeaturePacks manifest.
	//		And some styles must be initialized before startup AddContentDialog
	//		And for templates replacing must be initialized UTemplateProjectDefs
	if ( TemplateFullFilename.size( ) ) {
		// ParseManifestString need EContentSourceCategory, prepare UObject
		CreatePackage( L"/Script/AddContentDialog" );
		// Emulate call like from skipped DeferredCompiledInRegistration
		StaticEnum< EContentSourceCategory >( );
		// init FCoreStyle as FCoreStyle::ResetToDefault()
		FSlateApplication::Create( ); 
		// init FEditorStyle as FEditorStyle::SetStyle()
		if ( !FModuleManager::Get( ).LoadModule( L"EditorStyle" ) ) 
			UPC_LOG( "Fail load and startup UE4Editor-EditorStyle.dll" );
		Z_Construct_UClass_UDefaultTemplateProjectDefs();
	}

	UPC_TRACE( L"Run GameProjectUtils..." );
	FProjectInformation Info = {};
	Info.bShouldGenerateCode = bCodeGenerate;
	Info.DefaultGraphicsPerformance = Performance;
	Info.TargetedHardware = Hardware;
	Info.ProjectFilename = ProjectFullFilename.c_str( );
	Info.bIsBlankTemplate = bIsBlankTemplate;

	if ( TemplateFullFilename.size( ) ) {
		Info.TemplateFile = TemplateFullFilename.c_str( );
		const FString SrcFolder = FPaths::GetPath( Info.TemplateFile );
		// leak
		UTemplateProjectDefs* TemplateDefs = GameProjectUtils::LoadTemplateDefs( SrcFolder );
		if ( TemplateDefs ) {
			Info.bIsEnterpriseProject = TemplateDefs ->bIsEnterprise;
			Info.bIsBlankTemplate = TemplateDefs ->bIsBlank;
		}
		Info.bShouldGenerateCode = IFileManager::Get( ).DirectoryExists( 
			*( SrcFolder / ( L"Source" ) ) );
	}

	FText FailReason, FailLog;
	if ( GameProjectUtils::CreateProject( Info, FailReason, FailLog ) ) {
		FString AllDone = FString::Printf( 
				L"All done in %d milliseconds"
				, ( ::GetTickCount( ) - StartTick ) 
			);
		UPC_TRACE( *AllDone );
		return ERROR_SUCCESS;
	}

	// Print errors
	FString ReasonAndLog = *FTextInspector::GetSourceString( FText::Format( 
			INVTEXT( "Unable to create project. Reason [{0}]" )
			, FailReason 
		) );
	if ( !FailLog.IsEmpty( ) ) {
		ReasonAndLog += *FTextInspector::GetSourceString( FText::Format( 
				INVTEXT( " Log: [{0}]" )
				, FailLog 
			) );
	}
	UPC_TRACE( *ReasonAndLog );
	return ERROR_INVALID_FUNCTION;
}
};
}} // namespace prj_3d::UePrjCreator
