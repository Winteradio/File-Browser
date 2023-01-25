//#include "System.h"
#include "SUB_COM.h"
#define MAX 256
#include <string.h>

#include <filesystem>
#include <iostream>
#include <windows.h>

#include "BST.h"

int main()
{
	Node* No20 = new Node(20);
	Node* No5 = new Node(5);
	Node* No3 = new Node(3);
	Node* No15 = new Node(15);
	Node* No10 = new Node(10);
	Node* No17 = new Node(17);
	Node* No50 = new Node(50);
	Node* No30 = new Node(30);
	Node* No40 = new Node(40);

	Node* Cp40 = new Node(40);

	BST* bst = new BST;

	bst->Insert( No20 );
	bst->Insert( No5 );
	bst->Insert( No50 );
	/*
	bst->Insert( No3 );
	bst->Insert( No15 );
	bst->Insert( No17 );
	bst->Insert( No30 );
	bst->Insert( No40 );
	*/

	bst->InorderTraversal( Cp40 );

	system("pause");
	return 0;
}