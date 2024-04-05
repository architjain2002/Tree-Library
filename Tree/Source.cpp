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

	cout << tree;
	
	vector<char> vec = {'a','b','c',BinaryTree<char>::null,'d'};

	BinaryTree<char> tree2(vec);

	cout << tree2;

	return 0;
}