#ifndef __BST_H__
#define __BST_H__

#include "SUB_COM.h"
#include "Node.h"

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

typedef enum TraversalType
{
	INORDER,
	PREORDER,
	POSTORDER
}TraversalType;

class BST
{
	public :
		Node* RootNode = nullptr;

		void Insert( Node* node );
		void Delete( Node* node );
		void Search( Node* node, TraversalType Type );

		void InorderTraversal( Node* node );
		void PreorderTraversal( Node* node );
		void PostorderTraversal( Node* node );

		void GetSuccesor();
		void GetPredecessor();

		void Action( Node* OriginNode, Node* CompareNode );
};

#endif // __BST_H__