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

	BST::Insert( No20, nullptr );
	BST::Insert( No5, No20 );
	BST::Insert( No3, No20 );
	BST::Insert( No50, No20 );
	BST::Insert( No15, No20 );
	BST::Insert( No10, No20 );
	BST::Insert( No17, No20 );
	BST::Insert( No30, No20 );
	BST::Insert( No40, No20 );

	/*
	BST::Insert( No3 );
	BST::Insert( No15 );
	BST::Insert( No17 );
	BST::Insert( No30 );
	BST::Insert( No40 );
	*/

	LOG_INFO(" InorderTraversal ");

	BST::InorderTraversal( No20, &BST::Print );

	LOG_INFO(" PreorderTraversal ");
	BST::PreorderTraversal( No20, &BST::Print );

	LOG_INFO(" PostorderTraversal ");
	BST::PostorderTraversal( No20, &BST::Print );

	BST::GetSuccessor( No20, No20 );

	BST::Search( No15, No20, INORDER );

	system("pause");
	return 0;
}