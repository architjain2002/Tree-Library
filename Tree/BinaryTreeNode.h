#pragma once

template<typename T>
// TreeNode class to define a binary tree
class BinaryTreeNode {
public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	// default contructor with no arguments
	BinaryTreeNode();

	// constructor when the data is passed to the treeNode
	BinaryTreeNode(T data);
};

#include "BinaryTreeNode.hpp"