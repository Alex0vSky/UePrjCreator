// Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)
#include "stdafx.h"

// Posted here to speed up compilation
namespace prj_3d { namespace UePrjCreator {
namespace detail_ {
	MyArgs getArgparse(int argc, const char *argv[]) {
		return argparse::parse< MyArgs >( argc, argv );
	}
} // namespace detail_
}} // namespace prj_3d::UePrjCreator
