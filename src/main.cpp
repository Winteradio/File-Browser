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
	while( Play )
	{
		READTEXT::PrintFilesinDirectory( Path );
		LOG_INFO(" 0 : End ");
		LOG_INFO(" 1 : Upper ");
		LOG_INFO(" 2 : Down ");
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
			char Name[ MAXLENGTH ];
			printf(" Select File ");
			scanf("%s", &Name );
			READTEXT::PathGo2Down( Path, Name );
			break;
		default :
			break;
		}
		Sleep ( 500 );
	}


	system("pause");
	return 0;
}