// src\UeLocator.h - locate installation Unreal Engine
#pragma once // Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)
namespace prj_3d { namespace UePrjCreator {
struct UeLocator {
	// Well known registy location
	static std::map< std::wstring, std::wstring > getAllVersionToPath( ) {
		std::map< std::wstring, std::wstring > VerToPath;
		auto RegEnumerate = Reg::createEnumerate( Constants::getUnrealEngineRegistryKey( ) );
		if ( RegEnumerate ) {
			auto container = RegEnumerate ->all( );
			for (auto &var : container) {
				std::wstring InstalledDirectory;
				if ( var.second.readString( 
					Constants::getUnrealEngineRegistryValueName( )
					, InstalledDirectory 
				) ) 
				{
					VerToPath[ var.first ] = InstalledDirectory;
				}
			}
		}
		return VerToPath;
	}

	static int getPreferedDirectory(const std::wstring &UeVersion, std::wstring &UeInstallDir) {
		std::map< std::wstring, std::wstring > VerToPath = UeLocator::getAllVersionToPath( );
		if ( !VerToPath.size( ) ) {
			UPC_LOG( "Error! Not found Unreal Engine installation" );
			UPC_LOG( "Need pass a Unreal Engine installation path direct to UePrjCreator" );
			UPC_LOG( "Help: UePrjCreator.exe --help" );
			return ERROR_FILE_NOT_FOUND;
		}
		UPC_TRACE( "Founded Unreal Engine installations:" );
		for (auto it = VerToPath.rbegin( ); it != VerToPath.rend( ); ++it ) {
			UPC_TRACE( L"  [%s] = [%s]", it ->first.c_str( ), it ->second.c_str( ) );
		}
		if ( !UeVersion.empty( ) ) {
			UPC_TRACE( L"Try to load selected version of Unreal Engine: [%s]", UeVersion.c_str( ) );
			if ( !VerToPath.count( UeVersion.c_str( ) ) ) {
				UPC_LOG( "Error! Invalid Unreal Engine version" );
				return ERROR_BAD_ARGUMENTS;
			}
			UeInstallDir = VerToPath[ UeVersion.c_str( ) ];
		}
		else {
			UPC_TRACE( L"Try load a higher version of Unreal Engine: [%s]"
				, VerToPath.rbegin( ) ->first.c_str( ) );
			UeInstallDir = VerToPath.rbegin( ) ->second;
		}
		UPC_TRACE( L"  [%s]", UeInstallDir.c_str( ) );
		return ERROR_SUCCESS;
	}

};
}} // namespace prj_3d::UePrjCreator
