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

	while( READTEXT::Play )
	{
		READTEXT::Frame();
	}

	system("pause");
	return 0;
}