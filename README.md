Imagine you have a bunch of boxes, and each box has some stuff in it. Now, let's say you want to organize these boxes in a special way so you can quickly find things.

A binary tree in C is like a special way of arranging these boxes. Each box is called a "node," and each node has at most two other boxes connected to it. These connected boxes are called the "children" of the current box. The box at the top is called the "root."

Here's the rule: For each box (node), the stuff in the left box is smaller than the stuff in the right box. So, if you start at the root and follow these rules, you can quickly find any box with the stuff you're looking for.

Let me break it down:

1. **Root:** The top box where everything begins.
2. **Node:** A box in the tree.
3. **Child:** A box connected below another box.
4. **Left and Right:** The two directions a box can have children.

So, it's like a family tree, but instead of people, you have boxes, and each box has rules about where its smaller and larger stuff goes.

In C, you can use code to create and work with these tree structures. For example, you might have a code like this to define a node:

```c
struct Node {
    int data;  // This is the stuff in the box.
    struct Node* left;  // The box to the left.
    struct Node* right;  // The box to the right.
};
```

With a binary tree, you can do things like adding new boxes, finding boxes with specific stuff, and organizing your stuff in a way that makes it easy to find. It's like having a smart way to organize and search through your boxes of stuff!
---

---
# Task 0: Binary Tree Node Creation
============================================================

## Objective
The goal of this task is to create a function that generates a binary tree node. This function takes a pointer to the parent node and a value, and it returns a new node with the specified parent and value. The created node initially has no children.

## Function Signature
```c
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
```

## Parameters
- `parent`: A pointer to the parent node of the node to be created.
- `value`: The value to be stored in the new node.

## Return Value
- A pointer to the newly created node.
- If memory allocation fails, the function returns `NULL`.

## Example Usage
```c
binary_tree_t *root;

root = binary_tree_node(NULL, 98);

root->left = binary_tree_node(root, 12);
root->left->left = binary_tree_node(root->left, 6);
root->left->right = binary_tree_node(root->left, 16);

root->right = binary_tree_node(root, 402);
root->right->left = binary_tree_node(root->right, 256);
root->right->right = binary_tree_node(root->right, 512);
```

## Explanation
This example demonstrates the creation of a binary tree using the `binary_tree_node` function. The `root` node is created with a value of 98, and child nodes are added with values 12, 6, 16, 402, 256, and 512. The resulting tree structure is printed for visualization.

## Notes
- The created node does not initially have any children.
- The function is designed to handle the dynamic allocation of memory for the new node and returns `NULL` on failure.
- The provided example showcases the usage of the function to construct a binary tree.
---

---
# Task 1: Insert Left Child into Binary Tree
=============================================================

## Objective
The purpose of this task is to implement a function that inserts a node as the left-child of another node in a binary tree. The function is designed to create a new node with a given value and set it as the left-child of the specified parent node. If the parent node already has a left-child, the new node takes its place, and the old left-child becomes the left-child of the new node.

## Function Signature
```c
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
```

## Parameters
- `parent`: A pointer to the node to insert the left-child into.
- `value`: The value to store in the new node.

## Return Value
- A pointer to the newly created node.
- If memory allocation fails or if the parent is NULL, the function returns `NULL`.

## Example Usage
```c
binary_tree_t *root;

root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);

binary_tree_insert_left(root->right, 128);
binary_tree_insert_left(root, 54);
```

## Explanation
This example demonstrates the usage of the `binary_tree_insert_left` function to insert nodes into a binary tree. Nodes with values 128 and 54 are inserted as left-children of specific parent nodes. If the parent already has a left-child, the new node takes its place, and the old left-child becomes the left-child of the new node.

## Notes
- The function handles dynamic memory allocation for the new node.
- If memory allocation fails or if the parent is NULL, the function returns `NULL`.
- The resulting tree structure can be visualized using the provided `binary_tree_print` function or similar visualization methods.
---

---
# Task 2: Insert Right Child into Binary Tree
==================================================

## Objective
The goal of this task is to implement a function that inserts a node as the right-child of another node in a binary tree. The function creates a new node with a given value and sets it as the right-child of the specified parent node. If the parent node already has a right-child, the new node takes its place, and the old right-child becomes the right-child of the new node.

## Function Signature
```c
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
```

## Parameters
- `parent`: A pointer to the node to insert the right-child into.
- `value`: The value to store in the new node.

## Return Value
- A pointer to the newly created node.
- If memory allocation fails or if the parent is NULL, the function returns `NULL`.

## Example Usage
```c
binary_tree_t *root;

root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);

binary_tree_insert_right(root->left, 54);
binary_tree_insert_right(root, 128);
```

## Explanation
This example demonstrates the usage of the `binary_tree_insert_right` function to insert nodes into a binary tree. Nodes with values 54 and 128 are inserted as right-children of specific parent nodes. If the parent already has a right-child, the new node takes its place, and the old right-child becomes the right-child of the new node.

## Notes
- The function handles dynamic memory allocation for the new node.
- If memory allocation fails or if the parent is NULL, the function returns `NULL`.
- The resulting tree structure can be visualized using the provided `binary_tree_print` function or similar visualization methods.
---

---
# Task 3: Delete Binary Tree
========================================================

## Objective
The objective of this task is to implement a function that deletes an entire binary tree. The function takes a pointer to the root node of the tree and recursively deletes the entire tree, freeing the memory associated with each node.

## Function Signature
```c
void binary_tree_delete(binary_tree_t *tree);
```

## Parameters
- `tree`: A pointer to the root node of the tree to delete.

## Behavior
- If `tree` is `NULL`, the function does nothing.
- The function recursively deletes the left and right subtrees before freeing the memory of the current node.

## Example Usage
```c
binary_tree_t *root;

root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
binary_tree_insert_right(root->left, 54);
binary_tree_insert_right(root, 128);

binary_tree_delete(root);
```

## Explanation
This example demonstrates the usage of the `binary_tree_delete` function to delete an entire binary tree. The function is called with the root node, and it recursively deletes the left and right subtrees before freeing the memory of each node. After the deletion, the tree is effectively removed from memory.

## Notes
- The function uses a post-order traversal to ensure that child nodes are deleted before their parents.
- Deleting a tree using this function ensures that all memory allocated for nodes is properly freed.
- The function is safe to use even if the root node (`tree`) is `NULL`.
- Ensure that the tree is no longer accessed or used after calling this function, as the memory is deallocated.
---

---
# Task 4: Check if Node is a Leaf
================================================

## Objective
The objective of this task is to implement a function that checks whether a given node in a binary tree is a leaf. A leaf node is defined as a node that has no left or right children.

## Function Signature
```c
int binary_tree_is_leaf(const binary_tree_t *node);
```

## Parameters
- `node`: A pointer to the node to check.

## Return Value
- Returns 1 if the node is a leaf (has no left or right children).
- Returns 0 otherwise.
- If the input node is NULL, the function also returns 0.

## Example Usage
```c
binary_tree_t *root;

root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
binary_tree_insert_right(root->left, 54);
binary_tree_insert_right(root, 128);

int is_leaf = binary_tree_is_leaf(root);
// is_leaf will be 0 since root is not a leaf

is_leaf = binary_tree_is_leaf(root->right);
// is_leaf will be 0 since root->right is not a leaf

is_leaf = binary_tree_is_leaf(root->right->right);
// is_leaf will be 1 since root->right->right is a leaf
```

## Explanation
This example demonstrates the usage of the `binary_tree_is_leaf` function to check if specific nodes in a binary tree are leaves. The function returns 1 if a node is a leaf (has no left or right children) and 0 otherwise. If the input node is NULL, the function also returns 0.

## Notes
- The function is useful for determining whether a given node is a leaf in a binary tree.
- It is important to check for NULL input nodes to avoid undefined behavior.
- The resulting value can be used in conditional statements or as needed in the context of the binary tree operations.
---

---
# Task 5: Check if Node is a Root
=========================================

## Objective
The objective of this task is to implement a function that checks whether a given node in a binary tree is a root. A root node is defined as a node that has no parent.

## Function Signature
```c
int binary_tree_is_root(const binary_tree_t *node);
```

## Parameters
- `node`: A pointer to the node to check.

## Return Value
- Returns 1 if the node is a root (has no parent).
- Returns 0 otherwise.
- If the input node is NULL, the function also returns 0.

## Example Usage
```c
binary_tree_t *root;

root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
binary_tree_insert_right(root->left, 54);
binary_tree_insert_right(root, 128);

int is_root = binary_tree_is_root(root);
// is_root will be 1 since root is a root node

is_root = binary_tree_is_root(root->right);
// is_root will be 0 since root->right is not a root node

is_root = binary_tree_is_root(root->right->right);
// is_root will be 0 since root->right->right is not a root node
```

## Explanation
This example demonstrates the usage of the `binary_tree_is_root` function to check if specific nodes in a binary tree are root nodes. The function returns 1 if a node is a root (has no parent) and 0 otherwise. If the input node is NULL, the function also returns 0.

## Notes
- The function is useful for determining whether a given node is a root in a binary tree.
- It is important to check for NULL input nodes to avoid undefined behavior.
- The resulting value can be used in conditional statements or as needed in the context of the binary tree operations.
---

---
# Task 6: Pre-order Traversal of Binary Tree
=================================================
## Objective
The objective of this task is to implement a function that performs a pre-order traversal of a binary tree. Pre-order traversal involves visiting the current node before its left and right subtrees.

## Function Signature
```c
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
```

## Parameters
- `tree`: Pointer to the root node of the tree to traverse.
- `func`: Pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.

## Behavior
- If `tree` or `func` is NULL, the function does nothing.

## Example Usage
```c
binary_tree_t *root;

root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
root->left->left = binary_tree_node(root->left, 6);
root->left->right = binary_tree_node(root->left, 56);
root->right->left = binary_tree_node(root->right, 256);
root->right->right = binary_tree_node(root->right, 512);

binary_tree_preorder(root, &print_num);
```

## Explanation
This example demonstrates the usage of the `binary_tree_preorder` function to perform a pre-order traversal of a binary tree. The function calls a specified function for each node, following the order: current node, left subtree, right subtree. In this example, the `print_num` function is used to print the values of each visited node.

## Notes
- The function is useful for processing nodes in a specific order in a binary tree.
- It is important to check for NULL input nodes and function pointers to avoid undefined behavior.
- The resulting order of traversal can be utilized as needed in the context of binary tree operations.
---

---
# Task 7: In-order Traversal of Binary Tree
=========================================================

## Objective
The objective of this task is to implement a function that performs an in-order traversal of a binary tree. In-order traversal involves visiting the left subtree, followed by the current node, and then the right subtree.

## Function Signature
```c
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
```

## Parameters
- `tree`: Pointer to the root node of the tree to traverse.
- `func`: Pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.

## Behavior
- If `tree` or `func` is NULL, the function does nothing.

## Example Usage
```c
binary_tree_t *root;

root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
root->left->left = binary_tree_node(root->left, 6);
root->left->right = binary_tree_node(root->left, 56);
root->right->left = binary_tree_node(root->right, 256);
root->right->right = binary_tree_node(root->right, 512);

binary_tree_inorder(root, &print_num);
```

## Explanation
This example demonstrates the usage of the `binary_tree_inorder` function to perform an in-order traversal of a binary tree. The function calls a specified function for each node, following the order: left subtree, current node, right subtree. In this example, the `print_num` function is used to print the values of each visited node.

## Notes
- The function is useful for processing nodes in a specific order in a binary tree.
- It is important to check for NULL input nodes and function pointers to avoid undefined behavior.
- The resulting order of traversal can be utilized as needed in the context of binary tree operations.
---

---
# Task 8: Post-order Traversal of Binary Tree
=========================================================

## Objective
The objective of this task is to implement a function that performs a post-order traversal of a binary tree. Post-order traversal involves visiting the left subtree, the right subtree, and finally the current node.

## Function Signature
```c
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
```

## Parameters
- `tree`: Pointer to the root node of the tree to traverse.
- `func`: Pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.

## Behavior
- If `tree` or `func` is NULL, the function does nothing.

## Example Usage
```c
binary_tree_t *root;

root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
root->left->left = binary_tree_node(root->left, 6);
root->left->right = binary_tree_node(root->left, 56);
root->right->left = binary_tree_node(root->right, 256);
root->right->right = binary_tree_node(root->right, 512);

binary_tree_postorder(root, &print_num);
```

## Explanation
This example demonstrates the usage of the `binary_tree_postorder` function to perform a post-order traversal of a binary tree. The function calls a specified function for each node, following the order: left subtree, right subtree, current node. In this example, the `print_num` function is used to print the values of each visited node.

## Notes
- The function is useful for processing nodes in a specific order in a binary tree.
- It is important to check for NULL input nodes and function pointers to avoid undefined behavior.
- The resulting order of traversal can be utilized as needed in the context of binary tree operations.
---

---
# Task 9: Measure Height of Binary Tree
====================================================

## Objective
The objective of this task is to implement a function that measures the height of a binary tree.

## Function Signature
```c
size_t binary_tree_height(const binary_tree_t *tree);
```

## Parameters
- `tree`: Pointer to the root node of the tree to measure the height.

## Return
- If `tree` is NULL, the function returns 0.

## Overview
The `binary_tree_height` function calculates the height of a binary tree, which represents the length of the longest path from the root node to a leaf. The function returns 0 if the tree is empty (NULL).

## Example Usage
```c
binary_tree_t *root;
size_t height;

root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
binary_tree_insert_right(root->left, 54);
binary_tree_insert_right(root, 128);
binary_tree_print(root);

height = binary_tree_height(root);
printf("Height from %d: %lu\n", root->n, height);
height = binary_tree_height(root->right);
printf("Height from %d: %lu\n", root->right->n, height);
height = binary_tree_height(root->left->right);
printf("Height from %d: %lu\n", root->left->right->n, height);
```

## Explanation
This example demonstrates the usage of the `binary_tree_height` function to measure the height of a binary tree. The height is the length of the longest path from the root node to a leaf. The function returns 0 if the tree is empty (NULL). The provided `main` function prints the height from various nodes in the binary tree.

## Notes
- The height of an empty tree is 0.
- The height of a tree with only the root node is 1.
- The height is calculated as the length of the longest path to a leaf, including the root node.
- The function provides valuable information about the structure and balance of the binary tree.
---

---
# Task 10: Binary Tree Depth
==============================================

The goal of this task is to implement a function that measures the depth of a given node in a binary tree. The depth of a node is defined as the number of edges on the path from the node to the root of the tree. The function should return 0 if the provided node is NULL.

## Function Signature

```c
size_t binary_tree_depth(const binary_tree_t *tree);
```

### Parameters

- `tree`: A pointer to the node for which the depth needs to be measured.

### Return Value

- The function should return the depth of the node.

## Example

```c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

int main(void)
{
    binary_tree_t *root;
    size_t depth;

    // Create a sample binary tree
    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    // Measure the depth of different nodes
    depth = binary_tree_depth(root);
    printf("Depth of %d: %lu\n", root->n, depth);
    depth = binary_tree_depth(root->right);
    printf("Depth of %d: %lu\n", root->right->n, depth);
    depth = binary_tree_depth(root->left->right);
    printf("Depth of %d: %lu\n", root->left->right->n, depth);

    return (0);
}
```

Expected Output:

```
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Depth of 98: 0
Depth of 128: 1
Depth of 54: 2
```

Note: The depth is measured in terms of edges, so the depth of the root is 0.
---

---
# Task 12: Counting leaves in a Binary tree
==============================================

The goal of this task is to create a function called `binary_tree_leaves` that counts the number of leaves in a binary tree. A leaf is a node that has no children, i.e., both its left and right pointers are NULL. The function takes a pointer to the root node of the tree as its parameter and returns the count of leaves in the tree.

### Function Signature
```c
size_t binary_tree_leaves(const binary_tree_t *tree);
```

### Parameters
- `tree`: A pointer to the root node of the binary tree.

### Return Value
- The function returns the number of leaves in the binary tree.
- If the tree is NULL, the function returns 0.

### Example
```c
binary_tree_t *root;

root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
binary_tree_insert_right(root->left, 54);
binary_tree_insert_right(root, 128);
binary_tree_print(root);

size_t leaves = binary_tree_leaves(root);
printf("Leaves in %d: %lu\n", root->n, leaves);
```

This example creates a binary tree and then calls `binary_tree_leaves` to count the number of leaves in the tree. The result is printed to the console.
---

---
### Task 13 Readme: Binary Tree Nodes Count
==============================================

In this task, the objective is to write a function `binary_tree_nodes` that counts the number of nodes in a binary tree that have at least one child. A node with a child is a non-leaf node. The prototype for the function is as follows:

```c
size_t binary_tree_nodes(const binary_tree_t *tree);
```

#### Input

- `tree`: A pointer to the root node of the binary tree.

#### Output

The function returns the number of nodes in the binary tree that have at least one child. If the input tree is NULL, the function returns 0.

#### Example

Given a binary tree:

```
       .-------(098)--.
  .--(012)--.         .--(128)--.
(054)     (NULL)      (NULL)     (NULL)
```

The function `binary_tree_nodes` would return 1, as the root node (98) has one child (12).

```c
size_t nodes = binary_tree_nodes(root);
// nodes is now 1
```

#### Edge Case

If the input binary tree is NULL, the function returns 0.

```c
size_t nodes = binary_tree_nodes(NULL);
// nodes is 0
```

This function provides a way to count the number of non-leaf nodes in a binary tree, providing insight into the structure and complexity of the tree.
---

---
### Task 14 Readme: Binary Tree Balance Factor
===============================================

The task involves implementing a function `binary_tree_balance` that measures the balance factor of a binary tree. The balance factor of a binary tree is the difference between the heights of its left and right subtrees. The prototype for the function is as follows:

```c
int binary_tree_balance(const binary_tree_t *tree);
```

#### Input

- `tree`: A pointer to the root node of the binary tree.

#### Output

The function returns an integer representing the balance factor of the binary tree. If the input tree is NULL, the function returns 0.

#### Example

Given the following binary tree:

```
                      .-------(098)--.
            .-------(045)--.       (128)--.
       .--(012)--.       (050)          (402)
  .--(010)     (054)
(008)
```

The function `binary_tree_balance` would return:

```c
int balance = binary_tree_balance(root);
// balance is now +2
```

This indicates that the binary tree is unbalanced, with a positive balance factor, as the left subtree is taller than the right subtree.

#### Edge Case

If the input binary tree is NULL, the function returns 0.

```c
int balance = binary_tree_balance(NULL);
// balance is 0
```

This function is useful for assessing the balance of a binary tree, which is essential for maintaining efficient search and insertion operations in the tree.
---

---

