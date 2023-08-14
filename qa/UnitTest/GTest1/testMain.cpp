#include "pch.h"

namespace { class Environment0 : public ::testing::Environment {
	void SetUp() override {
		UePrjCreator::g_bVerbose = false;
		// Take all working sources to *.pdb file for OpenCppCoverage
		if ( false ) UePrjCreator::Main::run( 0, nullptr );
	}
}; auto g_unusedMain_ = testing::AddGlobalTestEnvironment( new Environment0 ); }
