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

#pragma warning( pop )



// include not Unreal Engine headers in last order to avoid conflict in _WINNT_
#pragma warning( push )
#pragma warning( disable: 4005 )
#include "sysw.h"
#pragma warning( pop )



#include "argparse.h"
