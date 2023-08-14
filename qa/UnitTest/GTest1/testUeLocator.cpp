#include "pch.h"

// Supress printf() @insp https://stackoverflow.com/questions/46728680/how-to-temporarily-suppress-output-from-printf
#pragma warning( push )
#pragma warning( disable: 4996 )
class PrintSupressor { 
	int m_fd;
	// @insp https://github.com/winfsp/cgofuse/issues/3
	static const int O_RDONLY = 0; static const int O_WRONLY = 1; static const int O_RDWR = 2;
 public:
	PrintSupressor() {
		fflush( stdout );
		m_fd = dup( 1 );
		int nullfd = open( "nul", O_WRONLY );
		dup2( nullfd, 1 );
		close( nullfd );
	}
	~PrintSupressor(){
		// Restore printf()
		fflush( stdout );
		dup2( m_fd, 1);
		close( m_fd );
	}
};
#pragma warning( pop )

namespace testMenu {
	static std::wstring s_UeVersion = L"4.26";

	struct MockRegistry;
	class Range {
		typedef std::map< std::wstring, const MockRegistry &> container_t;
		typedef container_t::iterator iterator_t;
		container_t m_container;
	public:
		Range();
		iterator_t begin() {
			return std::begin( m_container );
		}
		iterator_t end() {
			return std::end( m_container );
		}
	};

	struct MockRegistry {
		typedef Range allRv_t;
		struct RegEnum;
		MOCK_METHOD(std::optional< RegEnum >, createEnumerate_, ( const wchar_t *) );
		MOCK_METHOD(allRv_t, all_, (), (const) );
		MOCK_METHOD(bool, readString, (const wchar_t *, std::wstring &), (const) );

		static MockRegistry &Instance() {
			static MockRegistry s_MockRegistry;
			return s_MockRegistry;
		}

		// Proxies from static to mock
		struct RegEnum {
			static allRv_t all() {
				return MockRegistry::Instance( ).all_( );
			}
		};
		static std::optional< RegEnum > createEnumerate(const wchar_t *wcsKey) {
			return MockRegistry::Instance( ).createEnumerate_( wcsKey );
		}
	};
	Range::Range() {
		std::pair< std::wstring, const MockRegistry&> var( s_UeVersion, std::move( MockRegistry::Instance( ) ) );
		m_container.insert( std::move( var ) );
	}

	struct Context : public ::testing::Test {
		typedef UePrjCreator::UeLocator< MockRegistry > UeLocator_t;
		std::wstring m_UeInstallDir;
	};

typedef Context getPreferedDirectory;
NAMESPACE_TEST_F(UeLocator, getPreferedDirectory, succ) {

	EXPECT_CALL( MockRegistry::Instance( ), createEnumerate_( UePrjCreator::Constants::getUnrealEngineRegistryKey( ) ) )
		.WillOnce( Return( MockRegistry::RegEnum( ) ) );

	EXPECT_CALL( MockRegistry::Instance( ), all_( ) )
		.WillOnce( Return( Range{} ) );

	std::wstring ValueValueInCall = L"";
	std::wstring ValueValueOutCall = L"asd";
	EXPECT_CALL( MockRegistry::Instance( ), readString( UePrjCreator::Constants::getUnrealEngineRegistryValueName( ), ValueValueInCall ) )
		.WillOnce( 
				::testing::DoAll(
					::testing::SetArgReferee< 1 >( ValueValueOutCall )
					, Return( true )
				)
			)
		;
	EXPECT_TRUE( ERROR_SUCCESS == UeLocator_t::getPreferedDirectory( s_UeVersion, m_UeInstallDir ) );
	EXPECT_EQ( m_UeInstallDir, ValueValueOutCall );
}

typedef Context getPreferedDirectory;
NAMESPACE_TEST_F(UeLocator, getPreferedDirectory, fail) {

	EXPECT_CALL( MockRegistry::Instance( ), createEnumerate_( UePrjCreator::Constants::getUnrealEngineRegistryKey( ) ) )
		.WillOnce( Return( std::nullopt ) );

	bool b;
	{
		PrintSupressor scoped;
		b = ( ERROR_SUCCESS == UeLocator_t::getPreferedDirectory( s_UeVersion, m_UeInstallDir ) );
	}
	EXPECT_FALSE( b );
}

} // namespace testMenu _
