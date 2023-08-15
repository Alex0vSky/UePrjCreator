// Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)
#include "stdafx.h" // NOLINT(build/include_subdir)
#include "Main.h"

// Global variables for logging
namespace prj_3d { namespace UePrjCreator {
	bool g_bVerbose = true;
}} // namespace prj_3d::UePrjCreator

int wmain(int argc, wchar_t *argv[]) {
	return prj_3d::UePrjCreator::Main::run( argc, argv );
}
