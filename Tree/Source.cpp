#include<iostream>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
using namespace std;

int main() {

//	BinaryTreeNode<int> node(5);
	BinaryTree<int> tree;
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	//tree.insert(node);
	
	cout << tree;

	vector<char> vec = {'a','b','c',BinaryTree<char>::null,'d'};

	BinaryTree<char> tree2(vec);
	cout << tree2;

	BinaryTree<int> tree3(1, 2, 3, BinaryTree<int>::null, 4);
	cout << tree3;

	// copy constructor called (deep copy takes place)

	BinaryTree<int> tree4 = tree;
	cout << tree4;
	cout << tree4.getRoot() << " " << tree.getRoot() << std::endl;

	BinaryTree<int> tree5;
	tree5 = tree; // assignment operator is called and there is a shallow copy that happens to the member variables of the object
	cout << tree5;
	cout << tree5.getRoot() << " " << tree.getRoot() << std::endl;

	// move constructor this will make tree3->root = null and tree6->root = tree3->root
	BinaryTree<int> tree6(std::move(tree3));
	cout << tree6;

	BinaryTree<int> tree7;
	cout << tree6.size();
	return 0;
}