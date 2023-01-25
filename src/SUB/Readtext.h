#ifndef __READTEXT_H__
#define __READTEXT_H__

#define ALL_ORIGIN_FILE 0
#define SKIP_ORIGIN_FILE 1
#define OVERWRITE_ORIGIN_FILE 2
#define UPDATE_ORIGIN_FILE 3

#include "SUB_COM.h"
#include <string.h>
#include <filesystem>
#include <windows.h>

namespace FS = std::filesystem;

namespace READTEXT
{
	void FileLoad( const char* FileAddress );
	void FileRead();

	void FileCopy( FS::path OriginPath, FS::path NewPath, int OriginFileHandling );
	void FileMove( FS::path OriginPath, FS::path NewPath );
	void FileDelete( FS::path Path );

	bool CheckExisted( FS::path Path );
	void CheckFileType( FS::path Path );
	void CheckType( FS::path Path );

	void TypeWindow( FS::path Path );
	void TypeObject( FS::path Path );
	void TypeStory( FS::path Path );
	void TypeBrowser( FS::path Path );

	void PrintCurrentPath();
	void PrintRelativePath( FS::path Path );
	void PrintAbsolutePath( FS::path Path );
	void PrintCanonicalAbsoluatePath( FS::path Path );

	void PrintFilesinDirectory( FS::path Path );
	void PrintAllFilesinDirectory( FS::path Path );

	void CreateDirectory( FS::path Path );
	void CreateAllDirectory( FS::path Path );

	void PathGo2Up( FS::path& Path );
	void PathGo2Down( FS::path& Path );
}

#endif // __READTEXT_H__