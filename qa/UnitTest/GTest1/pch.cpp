// pch.cpp
#include "pch.h"

// From
//#include "..\..\src\_pch\stdafx.cpp"
	// Posted here to speed up compilation
	namespace prj_3d { namespace UePrjCreator {
	namespace detail_ {
		MyArgs getArgparse(int argc, const char *argv[]) {
			return argparse::parse< MyArgs >( argc, argv );
		}
	} // namespace detail_
	}} // namespace prj_3d::UePrjCreator
// From
//#include "..\..\src\EntryPoint.cpp"
	// Global variables for logging
	namespace prj_3d { namespace UePrjCreator {
		bool g_bVerbose = true;
	}} // namespace prj_3d::UePrjCreator


//// Common WinApi defines
//MOCK_DEFINE_FUNC( CheckDlgButton );
//MOCK_DEFINE_FUNC( GetModuleFileNameW );
//MOCK_DEFINE_FUNC( SetWindowLongPtrA );
//MOCK_DEFINE_FUNC( GetWindowLongPtrA );
//MOCK_DEFINE_FUNC( GetDlgItem );
//MOCK_DEFINE_FUNC( DestroyWindow );
//MOCK_DEFINE_FUNC( MessageBoxA );
//MOCK_DEFINE_FUNC( SetTimer );
//MOCK_DEFINE_FUNC( KillTimer );
