#include "BST.h"
#include <windows.h>

Node* BST::CompareNode = nullptr;
Node* BST::TempNode = nullptr;

void BST::NodeInit()
{
	CompareNode = nullptr;
	TempNode = nullptr;
}

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

void BST::Delete( Node* node, Node* RootNode )
{
	Search( node, RootNode, INORDER );

	if ( node->LeftChild != nullptr && node->RightChild != nullptr )
	{

	}
	else if ( node->LeftChild == nullptr && node->RightChild == nullptr )
	{

	}
	else
	{

	}

	LOG_INFO(" Delete Done ");
}

void BST::Search( Node* node, Node* RootNode, TraversalType Type )
{
	CompareNode = node;
	switch( Type )
	{
		case INORDER :
			InorderTraversal( RootNode, Find );
		break;

		case PREORDER :
			PreorderTraversal( RootNode, Find );
		break;

		case POSTORDER :
			PostorderTraversal( RootNode, Find );
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

void BST::GetSuccessor( Node* node, Node* RootNode )
{
	CompareNode = node;

	InorderTraversal( RootNode, CompareSuccessor );

	if ( TempNode != nullptr )
	{
		LOG_INFO(" Successor ");
		Print( TempNode );
	}
	else
	{
		LOG_INFO(" No Successor ");
	}

	NodeInit();
}

void BST::GetPredecessor( Node* node, Node* RootNode )
{
	CompareNode = node;

	InorderTraversal( RootNode, ComparePredecessor );

	if ( TempNode != nullptr )
	{
		LOG_INFO(" Predecessor ");
		Print( TempNode );
	}
	else
	{
		LOG_INFO(" No Predecessor ");
	}

	NodeInit();
}

void BST::Print( Node* node )
{
	LOG_INFO(" %d ", node->Value );
	Sleep( 100 );
}

void BST::CompareSuccessor( Node* node )
{
	if ( node->Value > CompareNode->Value )
	{
		if ( TempNode != nullptr )
		{
			if ( node->Value < TempNode->Value )
			{
				TempNode = node;
				Print( node );
				Sleep( 100 );
			}
		}
		else
		{
			TempNode = node;
		}
	}
}

void BST::ComparePredecessor( Node* node )
{
	if ( node->Value < CompareNode->Value )
	{
		if ( TempNode != nullptr )
		{
			if ( node->Value > TempNode->Value )
			{
				TempNode = node;
				Print( node );
				Sleep( 100 );
			}
		}
		else
		{
			TempNode = node;
		}
	}
}

void BST::Find( Node* node )
{
	if ( CompareNode->Value == node->LeftChild->Value || CompareNode->Value == node->RightChild->Value )
	{
		LOG_INFO(" Found Node ");
		Print( CompareNode );
		Sleep( 100 );
		TempNode = node;
	}
}