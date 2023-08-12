// src\FileSystem.h - few filesystem code
#pragma once // Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)
namespace prj_3d { namespace UePrjCreator { 
struct FileSystem;
namespace detail_ {
class Dir {
	std::filesystem::path m_Directory;
	Dir(const std::filesystem::path &Directory) : m_Directory( Directory ) 
	{}
	friend struct FileSystem;
public:
	std::filesystem::path getDirectoryPath() const {
		return m_Directory;
	}
	bool createFileAndWrite(const std::string &Filename, const std::string &Content) const {
		std::ofstream file( m_Directory / Filename, std::ios::binary );
		if ( !file.is_open( ) )
			return false;
		file << Content.c_str( );
		return file.good( );
	}
	Dir createSubDirectory(const std::filesystem::path &DirectoryName) const {
		std::filesystem::path Directory = m_Directory / DirectoryName;
		if ( !std::filesystem::create_directories( Directory ) )
			throw std::exception( );
		return Dir( Directory );
	}
};
} // namespace detail_ 
struct FileSystem {
	static detail_::Dir createTemporaryRootDirectory(std::filesystem::path &TemporaryDirectory) {
		std::filesystem::path TemporaryDirectoryBase = 
			std::filesystem::temp_directory_path( ) / "A0S_UePrjCreator_DevTpl";
		std::string str( "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" );
		std::mt19937 generator{ std::random_device{ }( ) };
		for ( int i = 0; i < 10; ++i ) {
			std::shuffle( str.begin( ), str.end( ), generator );
			TemporaryDirectory = TemporaryDirectoryBase / str.substr( 0, 7 );
			std::error_code nothrow_;
			if ( std::filesystem::create_directories( TemporaryDirectory, nothrow_ ) )
				return detail_::Dir( TemporaryDirectory.c_str( ) );
		}
		throw std::exception( );
	}
};
}} // namespace prj_3d::UePrjCreator
