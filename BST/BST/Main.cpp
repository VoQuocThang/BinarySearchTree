/*
         Programmer : Vo Quoc Thang
		 Date       : 30/1/2019
		 Content    : Binary Search Tree
		 Note       : Use pointers and Oriented-Object Programming 
*/
#include "BST.cpp"
#include <iostream>
using namespace std;

int main() {
	int arr[] = { 5,8,2,4,6,2,1 };
	BST<int> bst;
	for (int i = 0; i < 7; i++)  bst.add(arr[i]);
	bst.inOrderTraversal();
	bst.remove(2);
	bst.remove(1);
	bst.inOrderTraversal();
	bst.clear();
	system("pause");
	return 0;
}