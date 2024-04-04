#include<iostream>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
using namespace std;

int main() {

	BinaryTreeNode<int> node(5);
	BinaryTree<int> tree;
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(node);
	vector<int> arr = tree.inorder();

	cout << tree;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}