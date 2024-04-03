template <typename T>
BinaryTreeNode<T>::BinaryTreeNode() {
	this->data = T();
	this->left = nullptr;
	this->right = nullptr;
}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(T data) {
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

