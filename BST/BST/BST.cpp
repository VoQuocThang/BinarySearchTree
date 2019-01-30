#include "BST.h"


template <class T>
BST<T>::BST(): root(nullptr){}

/*
        Private area
*/

template <class T> 
bool  BST<T> ::searchHelper(Node<T> * r,T k) {
	if (r == nullptr) return false;
	if( r->getKey() == k) return true;
	if (r->getKey() > k) return searchHelper(r->getLeft(), k);
	else return searchHelper(r->getRight(), k);
}

/*
       Always add to a leave node
	   
*/
template <class T> 
Node<T> * BST<T> ::addHelper (Node<T> *r, Node<T> * p) {
	if (r == nullptr) return p;
	if(p->getKey() < r->getKey()) r->setLeft(addHelper(r->getLeft(), p));
	else r->setRight(addHelper(r->getRight(), p));
	return r;
}

/*
        Find the biggest node of the subtree has root r
*/
template<class T>
Node<T> * BST<T> ::successorNode(Node<T> *r,T & successorKey) {
	if (r->getRight() == nullptr) {
		successorKey = r->getKey();
		return removeNode(r);
	}
	r->setRight(successorNode(r->getRight(),successorKey));
	return r;
}

template <class T>
Node<T> * BST<T>::removeNode(Node<T> * r) {

	/*if node has only right child   
	  then replaced by right child
	*/

	 if (r->getLeft() == nullptr) {
		Node<T> * temp = r->getRight();
		delete r;
		return temp;
	}
    /* if node has only left child
	   then replaced by left child
	*/
	else if (r->getRight() == nullptr) {
		Node<T> * temp = r->getLeft();
		delete r;
		return temp;
	}
	/*  if node has both left and right chlid,
	    then find the biggest node in left-subtree to replace it
	*/
	else {
		int successorKey;
		r->setLeft( successorNode(r->getLeft(), successorKey) );
		r->setKey(successorKey);
		return r;
	}
}

template <class T> 
Node<T> * BST<T> ::removeHelper(Node<T> *r,T k) {
	if (r == nullptr) return nullptr;
	if (r->getKey() == k) {        
		   return removeNode(r);
	}
	if (r->getKey() > k)  r->setLeft(removeHelper(r->getLeft(), k));
	else r->setRight(removeHelper(r->getRight(), k));
	return r;
}

template<class T>
void BST<T> ::inOrder(Node<T> *r) {
	if (r == nullptr) return;
	inOrder(r->getLeft());
	std::cout << r->getKey()<<" ";
	inOrder(r->getRight());
}


/*
        Public area
*/
template <class T>
bool BST<T> :: search(T k) {
	return searchHelper(root, k);
}

template <class T> 
bool BST<T>:: add(T k) {
        if(search(k)) return false;
		Node<T> * p = new Node<T>(k);
		root = addHelper(root, p);
		return true;
}



template <class T>
bool BST<T>::remove(T k) {
	if (!search(k)) return false;
	root = removeHelper(root, k);
	return true;
}
/*
          Clear the tree by removing from root
*/
template<class T> 
void BST<T>::clear() {
	while (root != nullptr) remove(root->getKey());
}

template <class T>
void BST<T>::inOrderTraversal() {
	inOrder(root);
	std::cout << "\n";
}

template <class T> 
BST<T>::~BST()
{

}
