#include "BST.h"
#include <windows.h>

void BST::Insert( Node* ChildNode, Node* ParentNode )
{
	if ( ParentNode != nullptr )
	{
		if ( ChildNode->Value <= ParentNode->Value )
		{
			if ( ParentNode->LeftChild == nullptr )
			{
				ParentNode->LeftChild = ChildNode;
			}
			else
			{
				Insert( ChildNode, ParentNode->LeftChild );
			}
		}
		else if ( ChildNode->Value > ParentNode->Value )
		{
			if ( ParentNode->RightChild == nullptr )
			{
				ParentNode->RightChild = ChildNode;
			}
			else
			{
				Insert( ChildNode, ParentNode->RightChild );
			}
		}
	}
}

void BST::Delete( Node* node )
{
	
}

void BST::Search( Node* node, TraversalType Type )
{
	switch( Type )
	{
		case INORDER :
		break;

		case PREORDER :
		break;

		case POSTORDER :
		break;
	};
}

void BST::InorderTraversal( Node* node, void (*Action)( Node* ) )
{
	if ( node->LeftChild != nullptr )
	{
		InorderTraversal( node->LeftChild, Action );
	}

	Action( node );

	if ( node->RightChild != nullptr )
	{
		InorderTraversal( node->RightChild, Action);
	}
}

void BST::PreorderTraversal( Node* node, void (*Action)( Node* ) )
{
	Action( node );

	if ( node->LeftChild != nullptr )
	{
		PreorderTraversal( node->LeftChild, Action );
	}

	if ( node->RightChild != nullptr )
	{
		PreorderTraversal( node->RightChild, Action );
	}
}

void BST::PostorderTraversal( Node* node, void (*Action)( Node* ) )
{
	if ( node->LeftChild != nullptr )
	{
		PostorderTraversal( node->LeftChild, Action );
	}

	if ( node->RightChild != nullptr )
	{
		PostorderTraversal( node->RightChild, Action );
	}

	Action( node );
}

Node* BST::GetSuccesor( Node* node, Node* RootNode )
{
	Node* Succesor;



	return Succesor;
}

Node* BST::GetPredecessor( Node* node, Node* RootNode )
{
	Node* Predecessor;

	return Predecessor;
}

void BST::Print( Node* node )
{
	LOG_INFO(" %d ", node->Value );
	Sleep( 100 );
}