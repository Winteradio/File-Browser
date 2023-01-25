#ifndef __BST_H__
#define __BST_H__

#include "SUB_COM.h"
#include "Node.h"

typedef enum TraversalType
{
	INORDER,
	PREORDER,
	POSTORDER
}TraversalType;

class BST
{
	public :
		void Insert( int Value );
		void Delete( int Value );
		void Search( int Value, TraversalType Type );

		void InorderTraversal();
		void PreorderTraversal();
		void PostorderTraversal();

		void GetSuccesor();
		void GetPredecessor();


};

#endif // __BST_H__