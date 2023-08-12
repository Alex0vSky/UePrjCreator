// src\DevTpl.h - stored here template
#pragma once // Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)
namespace prj_3d { namespace UePrjCreator {
class DevTpl {
	std::filesystem::path m_TemporaryDirectory;
	std::wstring m_UProjectFullFilename;
	DevTpl() = default;
	void write_(detail_::Dir &RootDir, const std::string &UProjectFullFilename) {
		RootDir.createFileAndWrite( UProjectFullFilename.c_str( ), R"A0S_DELIM(
{
	"FileVersion": 3,
	"EngineAssociation": "",
	"Category": "",
	"Description": "",
	"Modules": [
	]
}
			)A0S_DELIM" );
		RootDir.createFileAndWrite( "contents.txt", R"A0S_DELIM(
../../../Templates/TP_devTpl/manifest.json
../../../Templates/TP_devTpl/Config/config.ini
			)A0S_DELIM" );
		RootDir.createFileAndWrite( "manifest.json", R"A0S_DELIM(
{
	"Version": 1,
	"Name":
	[
		{
			"Language": "en",
			"Text": "Blank from UePrjCreator"
		}
	],
	"Description":
	[
		{
			"Language": "en",
			"Text": "A clean empty project monolitic[without Editor] exe game from UePrjCreator."
		}
	],
	"AssetTypes": [],
	"SearchTags": [],
	"ClassTypes": "",
	"Category": "",
	"FocusAsset": "",
	"Screenshots":
	[
	],
	"SortKey": "TP_devTpl",
	"AdditionalFeaturePacks": []
}
			)A0S_DELIM" );
		auto SubDirSource = RootDir.createSubDirectory( "Source" );
		SubDirSource.createFileAndWrite( "TP_devTpl.Target.cs", R"A0S_DELIM(
using UnrealBuildTool;
using System.Collections.Generic;

public class TP_devTplTarget : TargetRules
{
	public TP_devTplTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		WindowsPlatform.bUseBundledDbgHelp = false;
		WindowsPlatform.bOptimizeGlobalData = false;
		WindowsPlatform.bCreateHotPatchableImage = false;
		bUseIncrementalLinking = true;
		bUsePDBFiles = false;
		bDisableDebugInfoForGeneratedCode = true;
		bUsePCHFiles = true;
		bDisableDebugInfo = true;
		bOmitPCDebugInfoInDevelopment = true;
		bAllowRemotelyCompiledPCHs = true;		
		bUseInlining = false; // need UBT with -OverrideBuildEnvironment
		LinkType = TargetLinkType.Monolithic;		
		ExtraModuleNames.AddRange( new string[] { "TP_devTpl" } );
	}
}
			)A0S_DELIM" );
		auto SubDirSourceTP_devTpl = SubDirSource.createSubDirectory( "TP_devTpl" );
		SubDirSourceTP_devTpl.createFileAndWrite( "TP_devTpl.Build.cs", R"A0S_DELIM(
using UnrealBuildTool;

public class TP_devTpl : ModuleRules
{
	public TP_devTpl(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		OptimizeCode = CodeOptimization.Never;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
			)A0S_DELIM" );

		SubDirSourceTP_devTpl.createFileAndWrite( "TP_devTpl.cpp", R"A0S_DELIM(
#include "TP_devTpl.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, TP_devTpl, "TP_devTpl" );
			)A0S_DELIM" );
		SubDirSourceTP_devTpl.createFileAndWrite( "TP_devTpl.h", R"A0S_DELIM(
#pragma once
#include "CoreMinimal.h"
			)A0S_DELIM" );
		SubDirSourceTP_devTpl.createFileAndWrite( "TP_devTplGameModeBase.cpp", R"A0S_DELIM(
#include "TP_devTplGameModeBase.h"
			)A0S_DELIM" );
		SubDirSourceTP_devTpl.createFileAndWrite( "TP_devTplGameModeBase.h", R"A0S_DELIM(
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TP_devTplGameModeBase.generated.h"

UCLASS()
class TP_DEVTPL_API ATP_devTplGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
};
			)A0S_DELIM" );

		auto SubDirConfig = RootDir.createSubDirectory( "Config" );
		SubDirConfig.createFileAndWrite( "config.ini", R"A0S_DELIM(
[Redirects]
GameName=TP_devTpl

[AdditionalFilesToAdd]
+Files=Templates/TP_devTpl/content/*.*
+Files=Templates/TP_devTpl/Source/TP_devTpl/TP_devTpl.h
+Files=Templates/TP_devTpl/Source/TP_devTpl/TP_devTplGameModeBase.cpp
+Files=Templates/TP_devTpl/Source/TP_devTpl/TP_devTplGameModeBase.h
			)A0S_DELIM" );
		SubDirConfig.createFileAndWrite( "DefaultEditor.ini", R"A0S_DELIM(
			)A0S_DELIM" );
		SubDirConfig.createFileAndWrite( "DefaultEngine.ini", R"A0S_DELIM(
			)A0S_DELIM" );
		SubDirConfig.createFileAndWrite( "DefaultGame.ini", R"A0S_DELIM(
[/Script/EngineSettings.GeneralProjectSettings]
ProjectID=433A7B804CE7CAC9021E63AF28FF6EE5
			)A0S_DELIM" );
		SubDirConfig.createFileAndWrite( "TemplateDefs.ini", R"A0S_DELIM(
[/Script/GameProjectGeneration.TemplateProjectDefs]

Categories=Games

LocalizedDisplayNames=(Language="en", Text="Blank from UePrjCreator")
LocalizedDescriptions=(Language="en", Text="A clean empty project monolitic[without Editor] exe game from UePrjCreator.")

ClassTypes=GameMode

FoldersToIgnore=Binaries
FoldersToIgnore=Build
FoldersToIgnore=Intermediate
FoldersToIgnore=Saved
FoldersToIgnore=Media

FilesToIgnore="%TEMPLATENAME%.uproject"
FilesToIgnore="%TEMPLATENAME%.png"
FilesToIgnore="Config/TemplateDefs.ini"
FilesToIgnore="Config/config.ini"
FilesToIgnore="%TEMPLATENAME%.opensdf"
FilesToIgnore="%TEMPLATENAME%.sdf"
FilesToIgnore="%TEMPLATENAME%.v11.suo"
FilesToIgnore="%TEMPLATENAME%.v12.suo"
FilesToIgnore="%TEMPLATENAME%.sln"
FilesToIgnore="Manifest.json"
FilesToIgnore="contents.txt"

FolderRenames=(From="Source/%TEMPLATENAME%", To="Source/%PROJECTNAME%")

FilenameReplacements=(Extensions=("cpp","h","ini","cs"), From="%TEMPLATENAME_UPPERCASE%", To="%PROJECTNAME_UPPERCASE%", bCaseSensitive=true)
FilenameReplacements=(Extensions=("cpp","h","ini","cs"), From="%TEMPLATENAME_LOWERCASE%", To="%PROJECTNAME_LOWERCASE%", bCaseSensitive=true)
FilenameReplacements=(Extensions=("cpp","h","ini","cs"), From="%TEMPLATENAME%", To="%PROJECTNAME%", bCaseSensitive=false)

ReplacementsInFiles=(Extensions=("cpp","h","ini","cs"), From="%TEMPLATENAME_UPPERCASE%", To="%PROJECTNAME_UPPERCASE%", bCaseSensitive=true)
ReplacementsInFiles=(Extensions=("cpp","h","ini","cs"), From="%TEMPLATENAME_LOWERCASE%", To="%PROJECTNAME_LOWERCASE%", bCaseSensitive=true)
ReplacementsInFiles=(Extensions=("cpp","h","ini","cs"), From="%TEMPLATENAME%", To="%PROJECTNAME%", bCaseSensitive=false)

; The sort key to use for the template to bypass the default alphabetical sorting.
SortKey="_1"
			)A0S_DELIM" );
	}

public:
	static DevTpl &Get() {
		static DevTpl DevTpl;
		return DevTpl;
	}
	static void removeTemporaryDirectories( ) {
		std::error_code nothrow_;
		std::filesystem::path TemporaryDirectory = Get( ).m_TemporaryDirectory;
		if ( TemporaryDirectory.empty( ) ) 
			return;
		UPC_TRACE( L"remove temporary directories [%s]", TemporaryDirectory.c_str( ) );
		std::filesystem::remove_all( TemporaryDirectory, nothrow_ );
	}
	bool CreateTemplateInTemporaryDirectory() {
		removeTemporaryDirectories( );
		std::atexit( removeTemporaryDirectories );
		std::at_quick_exit( removeTemporaryDirectories );
		try {
			detail_::Dir RootDir = FileSystem::createTemporaryRootDirectory( m_TemporaryDirectory );
			std::string UProjectFullFilename = "TP_devTpl.uproject";
			write_( RootDir, UProjectFullFilename );

			m_UProjectFullFilename = RootDir.getDirectoryPath( ) / UProjectFullFilename;
			UPC_TRACE( L"DevTlp [%s]", m_UProjectFullFilename.c_str( ) );
			return true;
		} catch(const std::exception &) {
			m_TemporaryDirectory.clear( );
		}
		return false;
	}
	std::wstring getFullFilename( ) const {
		return m_UProjectFullFilename;
	}
};
}} // namespace prj_3d::UePrjCreator
