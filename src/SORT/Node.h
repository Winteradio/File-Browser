#ifndef __NODE_H__
#define __NODE_H__

struct Node
{
	int Value = NULL;
	Node* LeftChild = nullptr;
	Node* RightChild = nullptr;

	Node( int Value )
	{
		this->Value = Value;
	}
};

#endif // __NODE_H__