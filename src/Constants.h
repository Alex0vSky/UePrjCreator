// src\Constants.h - constant values
#pragma once // Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)
namespace prj_3d { namespace UePrjCreator {
struct Constants {

static auto getVersion() {
	static const auto value = ( 
"UePrjCreator version " A0S_STRING_VERSION "\n"
		);
	return value;
}

static auto getCopyright() {
	static const auto value = ( A0S_Copyright "\n\n" );
	return value;
}

static auto getUsage() {
	static const auto value = ( 
"Create *.uproject file for Unreal Engine from command line\n\n"
		);
	return value;
}

static auto getUnrealEngineCommandLine() {
	static const auto value = ( 
L" -FullStdOutLogOutput -nothreading -noshaderworker -NoEnginePlugins"
		);
	return value;
}

// In root HKEY_LOCAL_MACHINE
static auto getUnrealEngineRegistryKey() {
	static const auto value = ( 
LR"(SOFTWARE\EpicGames\Unreal Engine)"
		);
	return value;
}

static auto getUnrealEngineRegistryValueName() {
	static const auto value = ( 
LR"(InstalledDirectory)"
		);
	return value;
}

};
}} // namespace prj_3d::UePrjCreator
