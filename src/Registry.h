// src\Registry.h - minor registry operations
#pragma once // Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)
namespace prj_3d { namespace UePrjCreator {
namespace detail_ {
class BaseReg {
protected:
	static const REGSAM m_Desired = KEY_READ;
	static const DWORD m_Options = REG_OPTION_NON_VOLATILE; // default
	const HKEY m_hKey;
	struct Buffer {
		static const int c_Chars = MAX_PATH;
		mutable wchar_t m_Data[ c_Chars + 1 ];
		static const int c_Bytes = c_Chars * sizeof( m_Data[ 0 ] );
	} m_buf;
	explicit BaseReg(HKEY hKey) : m_hKey( hKey ), m_buf{}
    {}
public:
	BaseReg &operator = (const BaseReg &) = delete;
};
} // namespace detail_

class Reg : public detail_::BaseReg {
	using detail_::BaseReg::BaseReg;

	class RegEnum : public detail_::BaseReg {
		using detail_::BaseReg::BaseReg;

	public:
		auto all() const {
			std::map< std::wstring, const Reg > Return;
			DWORD i = 0;
			LSTATUS lst;
			while ( ERROR_SUCCESS == ( lst = 
				::RegEnumKeyW( m_hKey, i++, m_buf.m_Data, m_buf.c_Chars ) 
			) ) { 
				HKEY hKey = 0;
				LSTATUS lstOpen = ::RegOpenKeyExW( 
					m_hKey, m_buf.m_Data, m_Options, m_Desired, &hKey );
				if ( ERROR_SUCCESS != lstOpen ) 
					continue;
				std::pair< const std::wstring, const Reg > var( 
					m_buf.m_Data, Reg( hKey ) );
				Return.insert( var );
			}
			if ( ERROR_NO_MORE_ITEMS != lst ) 
				::SetLastError( lst );
			return Return;
		}
		friend class Reg;
	};

public:
	bool readString(const wchar_t *ValueName, std::wstring &ValueValue) const { 
		DWORD Type = REG_SZ;
		DWORD cbData = m_buf.c_Bytes;
		LSTATUS lst = ::RegQueryValueExW( 
			m_hKey, ValueName, nullptr, &Type, reinterpret_cast< LPBYTE >( m_buf.m_Data ), &cbData );
		if ( ERROR_SUCCESS != lst )
			return false;
		// is NOT guaranteed to be null-terminated.
		DWORD CountChars = ( cbData - 1 ) / sizeof( m_buf.m_Data[ 0 ] );
		ValueValue = std::wstring( m_buf.m_Data, CountChars );
		return true;
	}
	
	static std::optional< RegEnum > createEnumerate(const wchar_t *wcsKey) {
		HKEY hKey = 0;
		LSTATUS lstOpen = ::RegOpenKeyExW( 
			HKEY_LOCAL_MACHINE, wcsKey, m_Options, m_Desired, &hKey );
		if ( ERROR_SUCCESS != lstOpen ) 
			return {};
		return RegEnum( hKey );
	}
};
}} // namespace prj_3d::UePrjCreator
