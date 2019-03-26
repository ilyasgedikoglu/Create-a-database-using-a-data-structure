#ifndef _FILENODE_
#define _FILENODE_

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include"WordNode.h"

using namespace std;
template <class T>
class FileNode 
{
public:
	T data;
	FileNode<T> *next;
	WordNode<T> *nextW;
	
	FileNode() :next(NULL) {}
	FileNode(const T &d) :data(d), next(NULL), nextW(NULL){}
};

#endif