#pragma once
#define UE_BUILD_DEVELOPMENT 1

// Correct vtable for UObject\Class.h
#define WITH_EDITOR	1
#define WITH_HOT_RELOAD 1
#define HACK_HEADER_GENERATOR 1

// Correct vtable for UObject\Object.h
#define WITH_ENGINE	1

// Default for installed Ue
#define STATS 1

#define WITH_UNREAL_DEVELOPER_TOOLS	0
#define WITH_PLUGIN_SUPPORT	0
#define IS_MONOLITHIC 0
#define IS_PROGRAM 0
#define UBT_COMPILED_PLATFORM Windows
#define PLATFORM_WINDOWS 1
#define CORE_API __declspec(dllimport)
#define _TCHAR_DEFINED
#define TRACELOG_API

#ifdef __clang__
#	pragma clang diagnostic ignored "-Wunknown-warning-option"
#	pragma clang diagnostic ignored "-Wnonportable-include-path"
#	pragma clang diagnostic ignored "-Wmicrosoft-include"
#	pragma clang diagnostic ignored "-Wdeprecated-builtins"
#	pragma clang diagnostic ignored "-Wswitch"
#	pragma clang diagnostic ignored "-Wunused-variable"
#	pragma clang diagnostic ignored "-Wbitwise-instead-of-logical"
#	pragma clang diagnostic ignored "-Winconsistent-missing-override"
#	pragma clang diagnostic ignored "-Wunused-local-typedef"
#	pragma clang diagnostic ignored "-Wunused-function"
#	pragma clang diagnostic ignored "-Wgnu-string-literal-operator-template"
#	pragma clang diagnostic ignored "-Wmicrosoft-unqualified-friend"
#	pragma clang diagnostic ignored "-Wtautological-undefined-compare"
#	pragma clang diagnostic ignored "-Wunused-lambda-capture"
#	pragma clang diagnostic ignored "-Wignored-qualifiers"
#	pragma clang diagnostic ignored "-Wsign-compare"
#	pragma clang diagnostic ignored "-Wmissing-declarations"
#	pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
//	message for memories
#	if __clang_major__ > 12 && _MSC_VER == 1929
#		include <vadefs.h>
#		ifndef _INC_VADEFS
#			pragma message ( "\nFor correct include path, when new version clang, different then in Visual Studio: \nplease, set '$(VC_IncludePath);$(WindowsSDK_IncludePath);' value in <IncludePath> of current *.vcxproj file.\nDefault element <ExternalIncludePath> will work." )
#		endif // _INC_VADEFS
#	endif
#endif // __clang__

#pragma warning( push )
#pragma warning( disable: 4005 )
#pragma warning( disable: 4244 )

// Changeable Unreal Engine header location. Yes, only this slash '/'. One line for batch processing
#define A0S_UE C:/Ue
#define A0S_STRINGIZE_(x) #x
#define A0S_STR(x) A0S_STRINGIZE_(x)

// To make IntelliSense happy
#ifdef __INTELLISENSE__ 
#	include A0S_STR( A0S_UE\Engine\Source\Runtime\Core\Public\HAL\PreprocessorHelpers.h )
#	undef COMPILED_PLATFORM_HEADER
#	define COMPILED_PLATFORM_HEADER(Suffix) PREPROCESSOR_TO_STRING(PREPROCESSOR_JOIN(Windows\Windows, Suffix))
#endif

#define WITH_SERVER_CODE 0
#include A0S_STR( A0S_UE\Engine\Source\Runtime\Core\Public\CoreMinimal.h )
#define COREUOBJECT_API
#define PROJECTS_API
#define HARDWARETARGETING_API
#define GAMEPROJECTGENERATION_API 
#include A0S_STR( A0S_UE\Engine\Source\Editor\GameProjectGeneration\Public\GameProjectUtils.h )
#include A0S_STR( A0S_UE\Engine\Source\Editor\HardwareTargeting\Public\HardwareTargetingSettings.h )
#include A0S_STR( A0S_UE\Engine\Source\Runtime\Core\Public\Modules\ModuleManager.h )
#include A0S_STR( A0S_UE\Engine\Source\Runtime\Core\Public\Misc\CommandLine.h )
#include A0S_STR( A0S_UE\Engine\Source\Runtime\Core\Public\HAL\PlatformOutputDevices.h )
#include A0S_STR( A0S_UE\Engine\Source\Runtime\Core\Public\Misc\CoreDelegates.h )
#include A0S_STR( A0S_UE\Engine\Source\Runtime\Core\Public\Misc\ConfigCacheIni.h )

// for console
#define APPLICATIONCORE_API
#include A0S_STR( A0S_UE\Engine\Source\Runtime\ApplicationCore\Public\Windows\WindowsPlatformApplicationMisc.h )
#include A0S_STR( A0S_UE\Engine\Source\Runtime\ApplicationCore\Public\HAL\PlatformApplicationMisc.h )
#include A0S_STR( A0S_UE\Engine\Source\Runtime\Core\Public\Misc\OutputDeviceHelper.h )

// Support generate from TemplateFile
// AdditInclDIr "C:\Ue\Engine\Intermediate\Build\Win64\UE4Editor\Inc\SlateCore;C:\Ue\Engine\Source\Runtime\SlateCore\Public;C:\Ue\Engine\Intermediate\Build\Win64\UE4Editor\Inc\InputCore;C:\Ue\Engine\Source\Runtime\InputCore\Classes;"
#define INPUTCORE_API
#define SLATECORE_API
#define SLATE_API
#include A0S_STR( A0S_UE\Engine\Source\Runtime\Slate\Public\Framework\Application\SlateApplication.h )
// AdditInclDIr "C:\Ue\Engine\Intermediate\Build\Win64\UE4Editor\Inc\AddContentDialog;"
#define ADDCONTENTDIALOG_API
#include A0S_STR( A0S_UE\Engine\Source\Editor\AddContentDialog\Private\IContentSource.h )
// AdditInclDIr "C:\Ue\Engine\Source\Editor\AddContentDialog\Public;C:\Ue\Engine\Source;C:\Ue\Engine\Intermediate\Build\Win64\UE4Editor\Inc\GameProjectGeneration;"
#pragma warning( push )
#pragma warning( disable: 4291 )
#include A0S_STR( A0S_UE\Engine\Source\Editor\GameProjectGeneration\Classes\TemplateProjectDefs.h )
#pragma warning( pop )
#include A0S_STR( A0S_UE\Engine\Source\Runtime\Core\Public\HAL\FileManager.h )

// AdditInclDIr "C:\Ue\Engine\Source\Editor\EditorSubsystem\Public;C:\Ue\Engine\Source\Runtime\Engine\Public;C:\Ue\Engine\Intermediate\Build\Win64\UE4Editor\Inc\Engine;C:\Ue\Engine\Intermediate\Build\Win64\UE4Editor\Inc\EditorSubsystem;"
#define ENGINE_API
#define EDITORSUBSYSTEM_API
#pragma warning( push )
#pragma warning( disable: 4291 )
#include A0S_STR( A0S_UE\Engine\Source\Editor\GameProjectGeneration\Classes\DefaultTemplateProjectDefs.h )
#include A0S_STR( A0S_UE\Engine\Source\Editor\GameProjectGeneration\Public\ClassTemplateEditorSubsystem.h )
#pragma warning( pop )

#undef A0S_UE
#undef A0S_STRINGIZE_
#undef A0S_STR



// include not Unreal Engine headers in last order to avoid conflict in _WINNT_
//
// minimum operating system version your code supports: Windows XP
#define _WIN32_WINNT _WIN32_WINNT_WINXP
#include <sdkddkver.h>
// disable min and max macros
#define NOMINMAX
// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#pragma warning( pop )

#include <locale>
#include <string>
#include <map>
#include <vector>
#include <optional>
#include <fstream>
#include <random>


#include "ThirdParty\magic_enum.hpp"
#pragma warning( push )
#pragma warning( disable: 4244 )
#pragma warning( disable: 4101 )
#include "ThirdParty\argparse.hpp"
#pragma warning( pop )

// Posted here to speed up compilation
#include "Version.h"
#include "Constants.h"
namespace prj_3d { namespace UePrjCreator {
namespace detail_ {
	class morrisfranken_argparse : public argparse::Args {
		void welcome() override {
			std::cout << Constants::getUsage( );
		}
	};

	struct MyArgs : public morrisfranken_argparse {
		std::optional< std::string >
			&arg_0Uproject
												= arg(
"quoted path to new *.uproject file"
" e.g.: \"C:\\MyGame\\MyGame.uproject\"\n\t\t\t\t"
);

		std::optional< std::string >
			&arg_UnrealInstallation
												= kwarg(
			"UeInstallDir"
, "quoted path to Unreal Engine installation directory"
" e.g.: \"C:\\Program Files\\Epic Games\\UE_4.26\"\n\t\t\t\t"
);

		EGraphicsPreset::Type
			&arg_DefaultGraphicsPerformance
												= kwarg(
			"DefaultGraphicsPerformance"
, "like DefaultEngine.ini [/Script/HardwareTargeting.HardwareTargetingSettings]\n\t\t\t\t"
).set_default( "Scalable" );

		EHardwareClass::Type
			&arg_TargetedHardwareClass
												= kwarg(
			"TargetedHardwareClass"
, "like DefaultEngine.ini [/Script/HardwareTargeting.HardwareTargetingSettings]\n\t\t\t\t"
).set_default( "Desktop" );

		std::optional< std::string >
			&arg_UnrealVersion
												= kwarg(
			"UeVersion"
, "number version of Unreal Engine, if multiple found"
" e.g.: 4.26\n\t\t\t\t"
);

		std::optional< std::string >
			&arg_Tpl
												= kwarg(
			"Tpl"
, "quoted path to exists Unreal Engine template"
" , disable DevTpl\n\t\t\t\t"
);

		bool &arg_bDevTpl						= flag(
			"DevTpl"
, "generate special uproject for single *.exe game, without UeEditor-s dll"
).set_default( false );

		bool &arg_bShouldGenerateCode			= flag(
			"GenerateCode"
, "generate C++ code (affect only DevTpl)"
).set_default( true );
		bool &arg_bIsBlankTemplate				= flag(
			"Blank"
, "blank templates do not specify a default map (affect only DevTpl)"
).set_default( false );

		bool &arg_version						= flag(
			"version"
, "print version"
);

		bool &arg_quiet							= flag(
			"quiet,q"
, "suppress output"
);
	};
	MyArgs getArgparse(int argc, const char *argv[]);
} // namespace detail_
}} // namespace prj_3d::UePrjCreator
