#pragma once
#include "magic_enum.hpp"
#pragma warning( push )
#pragma warning( disable: 4244 )
#pragma warning( disable: 4101 )
#include "argparse.hpp"
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
"\n\t\t\t\t e.g.: \"C:\\Program Files\\Epic Games\\UE_4.26\"\n\t\t\t\t"
);

		EGraphicsPreset::Type
			&arg_DefaultGraphicsPerformance
												= kwarg(
			"DefaultGraphicsPerformance"
, "from DefaultEngine.ini [/Script/HardwareTargeting.HardwareTargetingSettings]\n\t\t\t\t"
).set_default( "Scalable" );

		EHardwareClass::Type
			&arg_TargetedHardwareClass
												= kwarg(
			"TargetedHardwareClass"
, "from DefaultEngine.ini [/Script/HardwareTargeting.HardwareTargetingSettings]\n\t\t\t\t"
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
, "generate special uproject for single *.exe game, without UeEditor-s dll\n\t\t\t\t"
).set_default( false );

		bool &arg_bShouldGenerateCode			= flag(
			"GenerateCode"
, "generate C++ code (affect only DevTpl)"
).set_default( true );
		bool &arg_bIsBlankTemplate				= flag(
			"Blank"
, "blank templates do not specify a default map (affect only DevTpl)\n\t\t\t\t"
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
