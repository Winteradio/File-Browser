//#include "System.h"
#include "SUB_COM.h"
#define MAX 256
#include <string.h>

#include <filesystem>
#include <iostream>
#include <windows.h>

namespace FS = std::filesystem;

int main()
{
	FS::path Path("./../../");

// Make Binary Search Tree
/*
	Concept : Every nodes are smaller thatn lefted nodes and bigger than righted nodes

		BST's minimum is located left in tree
		BST's Maximum is located right in tree

	Inorder Traversal : Start for root node
		Traver recursive left sud-tree,
		if sud-tree has not left sud-tree, visit this sud-tree,
		action for nodes and,
		traver recursive right sud-tree
		-> Sequencial Visitive

	Preorder Traversal : Visit for root node
		visit this node, action for this node,
		traver recursive left sud-tree and,
		traver recursive right sud-tree

	Postorder Traversal : Traver for root node
		Traver recursive left sud-tree,
		traver recursive right sud-tree and,
		visit this node, action for this node
*/
	system("pause");
	return 0;
}