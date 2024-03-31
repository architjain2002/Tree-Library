#include "TreeNode.h"

template <typename T>
TreeNode<T>::TreeNode() {
	this->data = T();
	this->left = nullptr;
	this->right = nullptr;
}

template <typename T>
TreeNode<T>::TreeNode(T data) {
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}
