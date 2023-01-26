//#include "System.h"
#include "SUB_COM.h"
#define MAX 256
#include <string.h>

#include <filesystem>
#include <iostream>
#include <windows.h>

#include "BST.h"
#include "Readtext.h"

int main()
{
	LOG::LEVEL = LOG_HIGH;
	FS::path Path = FS::current_path();

	bool Play = true;
	char Name[ MAXLENGTH ];
	FS::path TempPath;
	while( Play )
	{
		READTEXT::PrintFilesinDirectory( Path );
		LOG_INFO(" 0 : End Browser ");
		LOG_INFO(" 1 : Up Directory ");
		LOG_INFO(" 2 : Down Directory ");
		LOG_INFO(" 3 : Read File ");
		int Value;
		printf(" Input Value ");
		scanf("%d", &Value );

		switch( Value )
		{
		case 0 :
			Play = false;
			break;
		case 1:
			READTEXT::PathGo2Up( Path );
			break;
		case 2:
			printf(" Select File ");
			scanf("%s", &Name );
			READTEXT::PathGo2Down( Path, Name, false );
			break;
		case 3:
			printf(" Select File ");
			scanf("%s", &Name );
			TempPath= Path;
			READTEXT::PathGo2Down( Path, Name, true );
			READTEXT::FileRead( Path );
			Path = TempPath;
			break;
		default :
			break;
		}
		Sleep ( 200 );
	}


	system("pause");
	return 0;
}