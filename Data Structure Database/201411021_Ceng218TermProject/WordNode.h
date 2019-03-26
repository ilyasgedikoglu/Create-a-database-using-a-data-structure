#ifndef _WORDNODE_
#define _WORDNODE_
#include"FileNode.h"

template <class T>
class WordNode 
{
public:
	T wordData;
	WordNode<T> *next;

	WordNode() :next(NULL) {}
	WordNode(const T &d) :wordData(d), next(NULL) {}
};

#endif