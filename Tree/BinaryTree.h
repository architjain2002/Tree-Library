#pragma once
#include "BinaryTreeNode.h"
#include <string>
#include <queue>
#include <vector>

template<typename T>
class BinaryTree {
private:
	BinaryTreeNode<T>* root;
	
	// preorder traversal implementation private
	void preorderTraversal(BinaryTreeNode<T>* root, std::vector<T>& result);
	// inorder traversal implementation private
	void inorderTraversal(BinaryTreeNode<T>* root, std::vector<T>& result);
	// postorder traversal implementation private
	void postorderTraversal(BinaryTreeNode<T>* root, std::vector<T>& result);
public:
	// default constructor of the class
	BinaryTree();

	// inserting a data into the tree
	void insert(const T& data);

	// inserting a custom node created using BinaryTreenode class into the tree
	void insert(BinaryTreeNode<T> node);

	// finding a node from the tree based on the position described in the string(location)
	BinaryTreeNode<T>* find(const std::string &location);

	// preorder traversal of the tree
	std::vector<T> preorder();

	// inorder traversal of the tree
	std::vector<T> inorder();

	// postorder traversal of the tree 
	std::vector<T> postorder();
};

#include "BinaryTree.hpp"