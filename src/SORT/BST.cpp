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
				ParentNode = ParentNode->LeftChild;
				Insert( ChildNode, ParentNode );
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
				ParentNode = ParentNode->RightChild;
				Insert( ChildNode, ParentNode );
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
		case INORDER : InorderTraversal( node );
		break;

		case PREORDER : PreorderTraversal( node );
		break;

		case POSTORDER : PostorderTraversal( node );
		break;
	};
}

void BST::InorderTraversal( Node* node )
{
	if ( node->LeftChild != nullptr )
	{
		InorderTraversal( node->LeftChild );
	}

	Action( node );

	if ( node->RightChild != nullptr )
	{
		InorderTraversal( node->RightChild );
	}
}

void BST::PreorderTraversal( Node* node )
{
	Action( node );

	if ( node->LeftChild != nullptr )
	{
		PreorderTraversal( node->LeftChild );
	}

	if ( node->RightChild != nullptr )
	{
		PreorderTraversal( node->RightChild );
	}
}

void BST::PostorderTraversal( Node* node )
{
	if ( node->LeftChild != nullptr )
	{
		PostorderTraversal( node->LeftChild );
	}

	if ( node->RightChild != nullptr )
	{
		PostorderTraversal( node->RightChild );
	}

	Action( node );
}

void BST::GetSuccesor()
{
	
}

void BST::GetPredecessor()
{
	
}

void BST::Action( Node* node )
{
	LOG_INFO(" %d ", node->Value );
	Sleep( 100 );
}