#include "BST.h"

void BST::Insert( Node* node )
{
	if ( RootNode == nullptr )
	{
		RootNode = node;
		LOG_INFO("%d", RootNode->Value );
	}
	else
	{
		Node* OriginNode = RootNode;

		if ( node->Value <= RootNode->Value )
		{
			RootNode = RootNode->LeftChild;
			LOG_INFO(" Go to Left ");
			Insert( node );
		}
		else if ( node->Value > RootNode->Value )
		{
			RootNode = RootNode->RightChild;
			LOG_INFO(" Go to Right ");
			Insert( node );
		}

		RootNode = OriginNode;
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
	Node* pNode = RootNode;
	if ( RootNode->LeftChild != nullptr )
	{
		RootNode = RootNode->LeftChild;
		InorderTraversal( node );
	}
	else
	{
		RootNode = pNode;
		Action( RootNode, node );

		if ( RootNode->RightChild != nullptr )
		{
			RootNode = RootNode->RightChild;
			InorderTraversal( node );
		}
		else
		{
			RootNode = pNode;
		}
	}
}

void BST::PreorderTraversal( Node* node )
{
}

void BST::PostorderTraversal( Node* node )
{
}

void BST::GetSuccesor()
{
	
}

void BST::GetPredecessor()
{
	
}

void BST::Action( Node* OriginNode, Node* CompareNode )
{
	char Temp;
	if ( OriginNode->Value == CompareNode->Value )
	{
		Temp = 'Y';
	}
	else
	{
		Temp = 'N';
	}
	LOG_INFO(" Value %d : // Same : %c", OriginNode->Value, Temp );
}