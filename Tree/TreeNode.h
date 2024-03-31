#pragma once

template<typename T>

// TreeNode class to define a binary tree
class TreeNode {
public:
	T data;
	TreeNode* left;
	TreeNode* right;

	// default contructor with no arguments
	TreeNode();

	// constructor when the data is passed to the treeNode
	TreeNode(T data);

};

#include "TreeNode.hpp";