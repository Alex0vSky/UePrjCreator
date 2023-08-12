// src\Log.h - logging
#pragma once // Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)
// Unfortunately we use macro for formatter compile time checking:
//	Visual Studio SAL macros only works in "cl ... /analyze";
//	Visual Studio not support __attribute__((format(...)));
//	std::format -- UnrealEngine have C2666 errors in C++20;
//	repo fmtlib/fmt not generate warning even in C++20.
// Note for StaticAnalysis: using reinterpret_cast in printf/wprintf will be destroy native SAL
namespace prj_3d { namespace UePrjCreator {
extern bool g_bVerbose;
#define UPC_TRACE(fmt, ...) \
	do { if ( g_bVerbose ) { UPC_LOG( fmt, __VA_ARGS__ ); } } while( false )
#define UPC_LOG(fmt, ...) \
	do {																							\
		constexpr bool bWchar = std::is_convertible_v< decltype( fmt ), const wchar_t * >;			\
		constexpr bool bChar = std::is_convertible_v< decltype( fmt ), const char * >;				\
		static_assert( bWchar || bChar, "Print only wchar_t or char strings");						\
		bChar																						\
			? printf( (const char *)( fmt ), __VA_ARGS__ )											\
			: wprintf( (const wchar_t *)( fmt ), __VA_ARGS__ )										\
				;																					\
		printf( "\n" );																				\
	} while( false )

}} // namespace prj_3d::UePrjCreator
