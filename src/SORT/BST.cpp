#include "BST.h"
#include <windows.h>

Node* BST::FoundNode = nullptr;
Node* BST::CompareNode = nullptr;
Node* BST::SuccessorNode = nullptr;
Node* BST::PredecessorNode = nullptr;

void BST::NodeInit()
{
	FoundNode = nullptr;
	CompareNode = nullptr;
	SuccessorNode = nullptr;
	PredecessorNode = nullptr;
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

	if ( SuccessorNode != nullptr )
	{
		LOG_INFO(" Successor ");
		Print( SuccessorNode );
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

	if ( PredecessorNode != nullptr )
	{
		LOG_INFO(" Predecessor ");
		Print( PredecessorNode );
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
		if ( SuccessorNode != nullptr )
		{
			if ( node->Value < SuccessorNode->Value )
			{
				SuccessorNode = node;
				Print( node );
				Sleep( 100 );
			}
		}
		else
		{
			SuccessorNode = node;
		}
	}
}

void BST::ComparePredecessor( Node* node )
{
	if ( node->Value < CompareNode->Value )
	{
		if ( PredecessorNode != nullptr )
		{
			if ( node->Value > PredecessorNode->Value )
			{
				PredecessorNode = node;
				Print( node );
				Sleep( 100 );
			}
		}
		else
		{
			PredecessorNode = node;
		}
	}
}

void BST::Find( Node* node )
{
	if ( CompareNode->Value == node->Value )
	{
		LOG_INFO(" Found Node ");
		Print( node );
		Sleep( 100 );
		FoundNode = node;
	}
}