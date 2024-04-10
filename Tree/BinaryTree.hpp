template<typename T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template<typename T>
BinaryTree<T>:: BinaryTree(const std::vector<T>& nodes) {
    if (nodes.size() == 0) {
        root = nullptr;
    }
    else {
        if (nodes.size() == 1 && nodes[0] == BinaryTree<T>::null) {
            root = nullptr;
            return;
        }
        std::queue<BinaryTreeNode<T>*> q;

        BinaryTreeNode<T>* head = new BinaryTreeNode<T>(nodes[0]);
        this->root = head;

        int i = 1;
        size_t size = nodes.size();
        q.push(head);

        while(i<size && !q.empty()) {
            BinaryTreeNode<T>* front = q.front();
            q.pop();

            if (i<size && nodes[i] != BinaryTree<T>::null) {
                front->left = new BinaryTreeNode<T>(nodes[i]);
                q.push(front->left);
            }
            i++;
            if (i<size && nodes[i] != BinaryTree<T>::null) {
                front->right = new BinaryTreeNode<T>(nodes[i]);
                q.push(front->right);
            }
            i++;
        }
    }
    return;
}

template <typename T>
template <typename... Args>
BinaryTree<T>::BinaryTree(Args&&... args)
{
    std::vector<T> nodes = { std::forward<Args>(args)... };
    
    if (nodes.size() == 0) {
        this->root = nullptr;
    }
    else {
        if (nodes.size() == 1 && nodes[0] == BinaryTree<T>::null) {
            this->root = nullptr;
            return;
        }
        std::queue<BinaryTreeNode<T>*> q;

        BinaryTreeNode<T>* head = new BinaryTreeNode<T>(nodes[0]);
        this->root = head;

        int i = 1;
        size_t size = nodes.size();
        q.push(head);

        while (i < size && !q.empty()) {
            BinaryTreeNode<T>* front = q.front();
            q.pop();

            if (i < size && nodes[i] != BinaryTree<T>::null) {
                front->left = new BinaryTreeNode<T>(nodes[i]);
                q.push(front->left);
            }
            i++;
            if (i < size && nodes[i] != BinaryTree<T>::null) {
                front->right = new BinaryTreeNode<T>(nodes[i]);
                q.push(front->right);
            }
            i++;
        }
    }
    return;
}

template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& tree) : BinaryTree(const_cast<const BinaryTree<T>&>(tree)) {} // use of delegation constructor to call other constructor

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& tree) {
    if (tree.getRoot() == nullptr) {
        this->root = nullptr;
    }
    else {
        BinaryTreeNode<T>* root = tree.getRoot();
        BinaryTreeNode<T>* tempRoot = new BinaryTreeNode<T>(root->data);

        std::queue<std::pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>> q;
        q.push({ root,tempRoot });

        while (!q.empty()) {
            std::pair <BinaryTreeNode<T>*, BinaryTreeNode<T>*> front = q.front();
            q.pop();

            if (front.first->left) {
                front.second->left = new BinaryTreeNode<T>(front.first->left->data);
                q.push({ front.first->left,front.second->left });
            }

            if (front.first->right) {
                front.second->right = new BinaryTreeNode<T>(front.first->right->data);
                q.push({ front.first->right,front.second->right });
            }
        }
        this->root = tempRoot;
    }
    return;
}

template<typename T>
void BinaryTree<T>::operator=(const BinaryTree<T>& tree)
{
    if (tree.getRoot() == nullptr) {
        this->root = nullptr;
    }
    else {
        BinaryTreeNode<T>* root = tree.getRoot();
        BinaryTreeNode<T>* tempRoot = new BinaryTreeNode<T>(root->data);

        std::queue<std::pair<BinaryTreeNode<T>*, BinaryTreeNode<T>*>> q;
        q.push({ root,tempRoot });

        while (!q.empty()) {
            std::pair <BinaryTreeNode<T>*, BinaryTreeNode<T>*> front = q.front();
            q.pop();

            if (front.first->left) {
                front.second->left = new BinaryTreeNode<T>(front.first->left->data);
                q.push({ front.first->left,front.second->left });
            }

            if (front.first->right) {
                front.second->right = new BinaryTreeNode<T>(front.first->right->data);
                q.push({ front.first->right,front.second->right });
            }
        }
        this->root = tempRoot;
    }
    return;
}

template<typename T>
BinaryTree<T>::BinaryTree(BinaryTree<T>&& tree) noexcept {
    this->root = tree.getRoot();
    tree.root = nullptr;
    return;
}

template<typename T>
const T BinaryTree<T>::null = std::numeric_limits<T>::min();

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::getRoot() const
{
    return this->root;
}

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>:: operator[] (size_t index) {
    if (root == nullptr) return nullptr;

    std::queue<BinaryTreeNode<T>*> nodes;
    nodes.push(root);

    size_t currIndex = 0;
    while (!nodes.empty()) {
        BinaryTreeNode<T>* front = nodes.front();
        nodes.pop();

        if (currIndex == index) {
            return front;
        }

        if (front->left) {
            nodes.push(front->left);
        }
        if (front->right) {
            nodes.push(front->right);
        }
        currIndex++;
    }

    return nullptr;
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
void BinaryTree<T>::setRoot(BinaryTreeNode<T> root) {
    this->root = &root;
    return;
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
            else if (front->right == nullptr && front) {
                q.push(nullptr);
            }
        }
        os << '\n';
    }
    return os;
}

template<typename T>
bool BinaryTree<T>::operator== (const BinaryTree<T> &tree) {
    return isEqual(root, tree.root);
}

template<typename T>
bool BinaryTree<T>::operator!= (const BinaryTree<T>& tree) {
    return !isEqual(root, tree.root);
}

template<typename T>
bool BinaryTree<T>::isEqual(BinaryTreeNode<T>* node1, BinaryTreeNode<T>* node2) const {
    if (!node1 && !node2) return true;

    if (!node1 || !node2) return false;

    if (node1->data != node2->data) return false;

    return isEqual(node1->left, node2->left) && isEqual(node1->right, node2->right);
}

template<typename T>
int BinaryTree<T>:: size() {
    return size(root);
}

template <typename T>
int BinaryTree<T>::size(BinaryTreeNode<T>* node) {
    if (node == nullptr) return 0;
    else return size(node->left) + size(node->right) + 1;
}

template<typename T>
bool BinaryTree<T>::empty() const {
    if (this->root == nullptr) return true;
    else return false;
}

template<typename T>
int BinaryTree<T>::height() {
    return height(root);
}

template<typename T>
int BinaryTree<T>::height(BinaryTreeNode<T>* node) {
    if (node == nullptr) return 0;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return std::max(leftHeight, rightHeight) + 1;
}

template<typename T>
void BinaryTree<T>::clear() {
    clear(root);
}

template<typename T>
void BinaryTree<T>::clear(BinaryTreeNode<T>* &node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }
}

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::getParent(BinaryTreeNode<T>* node) {
    if (root == nullptr && root == node) return nullptr;

    std::queue<BinaryTreeNode<T>*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        BinaryTreeNode<T>* front = nodes.front();
        nodes.pop();

        if ((front->left && front->left == node) && (front->right && front->right == node)) {
            return front;
        }

        if (front->left) nodes.push(front->left);
        if (front->right) nodes.push(front->right);
    }

    return nullptr;
}

template<typename T>
BinaryTree<T>:: ~BinaryTree() {
    delete root;
}
