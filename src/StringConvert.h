// src\StringConvert.h - string conversion: wchar_t to char; char to wchar_t;
#pragma once // Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)
namespace prj_3d { namespace UePrjCreator {
struct StringConvert {
	class ArgvChar { 
		std::unique_ptr< const char *[] > m_argvPtrs;
		const char **m_argv;
		std::vector< std::string > m_stringStorage;
	public:
		ArgvChar(int argc, wchar_t *argv[]) 
			: m_argvPtrs( std::make_unique< const char *[]>( new const char *[ argc ] ) 
		) {
			m_argv = static_cast< const char ** >( m_argvPtrs.get( ) );
			for ( int i = 0; i < argc; ++i ) {
				m_stringStorage.push_back( StringConvert::wcsrtombs( argv[ i ] ) );
				m_argv[ i ] = m_stringStorage.back( ).c_str( );
			}
		}
		int argc() {
			return static_cast<int>( m_stringStorage.size( ) );
		}
		auto argv() {
			return m_argv;
		}
	};
	static const char *getLocaleOption() {
		static const char *sz = "en_US.utf8";
		return sz;
	}

	// TODO(Alex0vSky): do it like template
	static std::string wcsrtombs(const std::wstring &wcstr) {
		static bool bLocale = false;
		if ( !bLocale ) {
			std::setlocale( LC_ALL, getLocaleOption( ) );
			bLocale = true;
		}
		size_t len;
		const wchar_t *wstr = wcstr.c_str( );
		wcsrtombs_s( &len, nullptr, 0, &wstr, 0, nullptr );
		if ( len == static_cast< std::size_t >( -1 ) ) 
			throw std::logic_error( "Illegal byte sequence" );
		std::vector< char > plainMemory( len );
		wcsrtombs_s( nullptr, plainMemory.data( ), len, &wstr, len, nullptr );
		std::string mbstr( plainMemory.data( ), len - 1 );
		return mbstr;
	}
	static std::wstring mbsrtowcs(const std::string &mbstr) {
		static bool bLocale = false;
		if ( !bLocale ) {
			std::setlocale( LC_ALL, getLocaleOption( ) );
			bLocale = true;
		}
		size_t len;
		const char *str = mbstr.c_str( );
		mbsrtowcs_s( &len, nullptr, 0, &str, 0, nullptr );
		if ( len == static_cast< std::size_t >( -1 ) ) 
			throw std::logic_error( "Illegal byte sequence" );
		std::vector< wchar_t > plainMemory( len );
		mbsrtowcs_s( nullptr, plainMemory.data( ), len, &str, len, nullptr );
		std::wstring wcstr( plainMemory.data( ), len - 1 );
		return wcstr;
	}
};
}} // namespace prj_3d::UePrjCreator
