# BinaryTree Library

The BinaryTree library is a C++ toolkit designed to simplify binary tree operations. It provides a set of intuitive interfaces and functionalities for creating, manipulating, and traversing binary trees.

## Features

- **Simple Interface**: Easy-to-use constructors and member functions for creating and managing binary trees.
- **Templates**: Flexible tree creation and manipulation using templates.
- **Traversal Algorithms**: Implementations for preorder, inorder, and postorder traversals.
- **Iterator Support**: Level-order traversal iterator support for seamless integration with standard algorithms and data structures.
- **STL-like Feel**: Emulates the elegance and usability of STL containers for a familiar user experience.

## Getting Started

To get started with the BinaryTree library, follow these steps:

1. **Clone the Repository**: Clone the BinaryTree repository to your local machine using Git:

    ```
    git clone https://github.com/architjain2002/Tree-Library.git
    ```
    You can go ahead and build the files and include the header files directly in your project.
    You can also go ahead and download the static library in from the releases and include it in external libraries and use it accordingy.

2. **Include Headers**: Include the necessary header files in your C++ project:

    ```cpp
    #include "BinaryTree.h"
    #include "BinaryTreeNode.h"
    ```
## Usage of the library

1. **Create Binary Trees**: Use the BinaryTree library to create and manipulate binary trees in your code:
This will insert in a level order way.

    ```cpp
    // Example usage
    BinaryTree<int> tree1;
    tree1.insert(5);
    tree1.insert(3);
    tree1.insert(7);
    //  5
    // /\
    // 3 7
    
    // or you can insert it via nodes
    BinaryTreeNode<int> node(4);
    tree1.insert(node);

    vector<char> vec = {'a','b','c',BinaryTree<char>::null,'d'};
    BinaryTree<char> tree2(vec); // you can directly insert a vector through constructors

    // you can use variadic templates to also make an insertion
    BinaryTree<int> tree3(1, 2, 3, BinaryTree<int>::null, 4);
    ```

2. **Copy constructor**: To create a deep copy of the existent tree onto a new tree class object.

    ```cpp
	// copy constructor called (deep copy takes place)
	BinaryTree<int> tree4 = tree1;
    ```

4. **Move constructor**: To move a tree object to other tree object and clearing out the memory held by the previous tree object.

    ```cpp
	// move constructor this will make tree3->root = null and tree5->root = tree3->root
	BinaryTree<int> tree5(std::move(tree3));
    ```

5. **Assignment operator**: To create a deep copy of the existent tree onto a new tree class object.

    ```cpp
	BinaryTree<int> tree6;
	tree6 = tree; // assignment operator is called and there is a deep copy that happens to the member variables of the object
    ```
## Contributing

Contributions to the BinaryTree library are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request on GitHub.
