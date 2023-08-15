// src\CmdLiner.h - command line working
#pragma once // Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)
namespace prj_3d { namespace UePrjCreator {
class CmdLiner {
	StringConvert::ArgvChar m_ArgvChar;

 public:
	CmdLiner(int argc, wchar_t *argv[]) : m_ArgvChar( argc, argv )
    {}

	bool parse(
		  std::wstring &Filename
		, std::wstring &UeInstallDir
		, EGraphicsPreset::Type &Graphics
		, EHardwareClass::Type &Hardware
		, std::wstring &UeVersion
		, std::wstring &TemplateFile
		, bool &bDevTpl
		, bool &bShouldGenerateCode
		, bool &bIsBlankTemplate
		, bool &bVerbose
	) {
		int argc = m_ArgvChar.argc( );
		// Get parsed command line arguments
		detail_::MyArgs parsed = detail_::getArgparse( argc, m_ArgvChar.argv( ) );
		if ( 1 == argc ) {
	        std::cout << Constants::getVersion( );
			std::cout << Constants::getCopyright( );
			parsed.help( );
			return false;
		}
		if ( parsed.arg_version ) {
	        std::cout << Constants::getVersion( );
			exit( ERROR_SUCCESS );
		}
		if ( parsed.arg_0Uproject ) {
			if ( "/?" == *parsed.arg_0Uproject ) {
				parsed.help( );
				exit( ERROR_SUCCESS );
			}
			Filename = StringConvert::mbsrtowcs( *parsed.arg_0Uproject );
		} else {
			std::cout << 
				R"(Argument missing: arg_0 (quoted path to Unreal Engine installation directory e.g.: "C:\MyGame\MyGame.uproject")\n)";
			return false;
		}

		UeInstallDir.clear( );
		UeVersion .clear( );
		TemplateFile.clear( );
		if ( parsed.arg_UnrealInstallation )
			UeInstallDir = StringConvert::mbsrtowcs( *parsed.arg_UnrealInstallation );
		Graphics = parsed.arg_DefaultGraphicsPerformance;
		Hardware = parsed.arg_TargetedHardwareClass;
		if ( parsed.arg_UnrealVersion )
			UeVersion = StringConvert::mbsrtowcs( *parsed.arg_UnrealVersion );
		if ( parsed.arg_Tpl )
			TemplateFile = StringConvert::mbsrtowcs( *parsed.arg_Tpl );
		bDevTpl = parsed.arg_bDevTpl;
		bShouldGenerateCode = parsed.arg_bShouldGenerateCode;
		bIsBlankTemplate = parsed.arg_bIsBlankTemplate;

		if ( !TemplateFile.empty( ) ) {
			UPC_TRACE( L"DevTpl is disabled due to template passing" );
			bDevTpl = false;
		}

		bVerbose = !parsed.arg_quiet;
		return true;
	}
};
}} // namespace prj_3d::UePrjCreator
