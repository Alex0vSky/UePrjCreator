// src\Version.h - versioning, use PE-file resources via UePrjCreator.rc, file will be patched in CI
#pragma once // Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)
#define A0S_Copyright \
	"Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)"
#define A0S_VERSION_MAJOR 0
#define A0S_VERSION_MINOR 1
#define A0S_VERSION_PATCH 0
#define A0S_VERSION_BUILD 0

#define A0S_stringify(a) A0S_stringify_(a)
#define A0S_stringify_(a) #a

#define A0S_STRING_VERSION \
	    A0S_stringify( A0S_VERSION_MAJOR ) \
	"." A0S_stringify( A0S_VERSION_MINOR ) \
	"." A0S_stringify( A0S_VERSION_PATCH ) \
	"." A0S_stringify( A0S_VERSION_BUILD )

namespace prj_3d { namespace UePrjCreator {
struct Version { 
	static const char *getSemver( ) {
		static const char *szSemver = A0S_STRING_VERSION;
		return szSemver;
	}
};
}} // namespace prj_3d::UePrjCreator
