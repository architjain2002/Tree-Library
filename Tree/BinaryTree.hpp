template<typename T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template<typename T>
std::vector<T> BinaryTree<T>::preorder() {
    std::vector<T> result;
    preorderTraversal(root, result);
    return result;
}
        
template<typename T>
void BinaryTree<T>:: preorderTraversal(BinaryTreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) {
        return;
    }
    result.push_back(root->data);
    preorderTraversal(root->left, result);
    preorderTraversal(root->right, result);
    return;
}

template<typename T>
std::vector<T> BinaryTree<T>::inorder() {
    std::vector<T> result;
    inorderTraversal(root, result);
    return result;
}

template<typename T>
void BinaryTree<T>::inorderTraversal(BinaryTreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left, result);
    result.push_back(root->data);
    inorderTraversal(root->right, result);
    return;
}

template<typename T>
std::vector<T> BinaryTree<T>::postorder() {
    std::vector<T> result;
    postorderTraversal(root, result);
    return result;
}

template<typename T>
void BinaryTree<T>::postorderTraversal(BinaryTreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left, result);
    postorderTraversal(root->right, result);
    result.push_back(root->data);
    return;
}

template<typename T>
void BinaryTree<T>::insert(const T& data) {
    if (root == nullptr) {
        root = new BinaryTreeNode<T>(data);
    }
    else {
        std::queue<BinaryTreeNode<T>*> q;
        q.push(root);
        
        while (!q.empty()) {
            BinaryTreeNode<T>* front = q.front();
            q.pop();

            if (front->left == nullptr) {
                front->left = new BinaryTreeNode<T>(data);
                break;
            }
            else {
                q.push(front->left);
            }

            if (front->right == nullptr) {
                front->right = new BinaryTreeNode<T>(data);
                break;
            }
            else {
                q.push(front->right);
            }
        }
    }
    return;
}

template<typename T>
void BinaryTree<T>::insert(BinaryTreeNode<T> node) {
    if (root == nullptr) {
        root = &node;
    }
    else {
        std::queue<BinaryTreeNode<T>*> q;
        q.push(root);

        while (!q.empty()) {
            BinaryTreeNode<T>* front = q.front();
            q.pop();

            if (front->left == nullptr) {
                front->left = &node;
                break;
            }
            else {
                q.push(front->left);
            }

            if (front->right == nullptr) {
                front->right = &node;
                break;
            }
            else {
                q.push(front->right);
            }
        }
    }
    return;
}


template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::find(const std::string &location) {
    return new BinaryTreeNode<T>(T());
}

template<typename T>    
std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& tree) {
    std::queue<BinaryTreeNode<T>*>q;
    q.push(tree.root);

    while (!q.empty()) {
        size_t size = q.size();

        for (int i = 0; i < size; i++) {
            BinaryTreeNode<T>* front = q.front();
            q.pop();

            if (front) {
                os << front->data << " ";
            }
            else {
                os << "null" << " ";
                continue;
            }
            
            if (front->left) {
                q.push(front->left);
            }
            else if (front->left == nullptr && front) {
                q.push(nullptr);
            }
            if (front->right) {
                q.push(front->right);
            }
            else if(front->right == nullptr && front){
                q.push(nullptr);
            }
        }
        os << '\n';
    }
    
    return os;
}

