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
	// size implementation private
	int size(BinaryTreeNode<T>* node);
	// height implementation private
	int height(BinaryTreeNode<T>* node);
	// clear implementation private
	void clear(BinaryTreeNode<T>* &node);
	// equal implementation private
	bool isEqual(BinaryTreeNode<T>* node1, BinaryTreeNode<T>* node2) const;
public:

	static const T null;
	// default constructor of the class
	BinaryTree();

	// overloaded constructor of the class to create the binary tree by taking in a vector
	BinaryTree(const std::vector<T>& nodes);

	// overloaded constructor by using variadic templates to create the binary tree
	template <typename... Args>
	BinaryTree(Args&&... args);

	// copy constructor of the class, this internally will const_cast the tree object to const type and call the const copy constructor
	BinaryTree(BinaryTree<T>& tree);

	// copy constructor with const of the class
	BinaryTree(const BinaryTree<T>& tree);

	// copy assignment operator of the class
	void operator=(const BinaryTree<T>&);

	// move constructor of the class
	BinaryTree(BinaryTree<T>&& tree) noexcept;

	// printing the binary tree using operator overloading
	template<typename U>
	friend std::ostream& operator<< (std:: ostream& os, const BinaryTree<U>& tree);

	// to access the root of the BinaryTree of the class
	BinaryTreeNode<T>* getRoot() const;

	// to access a node of the binary tree using []
	BinaryTreeNode<T>* operator[] (size_t index);

	// to check for equality of two trees
	bool operator== (const BinaryTree<T> &tree);

	// to check for equality of two trees
	bool operator!= (const BinaryTree<T>& tree);

	// inserting a data into the tree
	void insert(const T& data);

	// inserting a custom node created using BinaryTreenode class into the tree
	void insert(BinaryTreeNode<T> node);

	// setting root to the custom created tree using BinaryTreeNode class
	void setRoot(BinaryTreeNode<T> root);

	// finding a node from the tree based on the position described in the string(location)
	BinaryTreeNode<T>* find(const std::string &location);

	// preorder traversal of the tree
	std::vector<T> preorder();

	// inorder traversal of the tree
	std::vector<T> inorder();

	// postorder traversal of the tree 
	std::vector<T> postorder();
	
	// to check if the binary tree is empty
	bool empty() const;

	// to get size of the binary tree
	int size();
	
	// height of the binary tree
	int height();

	// get parent of the binary tree node
	BinaryTreeNode<T>* getParent(BinaryTreeNode<T>* node);

	// get siblings of the binary tree node
	std::vector<T> getSiblings(BinaryTreeNode<T>* node);

	// clear binary tree
	void clear();

	// destructor
	~BinaryTree();
};

#include "BinaryTree.hpp"
