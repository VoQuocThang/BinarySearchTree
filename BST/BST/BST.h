#pragma once
#include "Node.cpp"
#include <iostream>
template <class T> 
class BST
{
private:
	Node<T> * root;
	bool searchHelper(Node<T> * r,T k);
	Node<T> * addHelper(Node<T> *r, Node<T> * p);
	Node<T> * removeHelper(Node<T> * r,T k);
	Node<T> * removeNode(Node<T> *);
	Node<T> * successorNode(Node<T> *,T & );
	void inOrder(Node<T> *r);
	
public:
	bool search(T);
	bool add(T);
	bool remove(T);
	void clear();
	void inOrderTraversal();
public:
	BST();
	~BST();
};

