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
## Task 15: Binary Tree Is Full
=================================================

The goal of this task is to create a function `binary_tree_is_full` that checks whether a given binary tree is full or not.

A full binary tree is a tree in which every node has either 0 or 2 children. In other words, every node must either have no children (be a leaf) or have two children. If any node has only one child, the tree is not considered full.

The function takes a pointer to the root node of the binary tree as its parameter. If the tree is full, the function returns 1; otherwise, it returns 0. If the tree is empty (i.e., the root node is NULL), the function also returns 0.

Example:
```c
binary_tree_t *root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
binary_tree_insert_right(root->left, 54);
binary_tree_insert_right(root, 128);
root->left->left = binary_tree_node(root->left, 10);

int is_full = binary_tree_is_full(root);
printf("Is the tree full? %d\n", is_full);
```

In this example, the tree is not full since the node with the value 12 has only one child. The function will return 0 in this case.
---

---
## Task 16: Binary Tree Is Perfect
=========================================

The objective of this task is to create a function `binary_tree_is_perfect` that checks whether a given binary tree is perfect or not.

A perfect binary tree is a binary tree in which all leaf nodes are at the same level, and every non-leaf node has exactly two children. In other words, a perfect binary tree is both full and balanced.

The function takes a pointer to the root node of the binary tree as its parameter. If the tree is perfect, the function returns 1; otherwise, it returns 0. If the tree is empty (i.e., the root node is NULL), the function also returns 0.

Example:
```c
binary_tree_t *root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 402);
binary_tree_insert_right(root->left, 54);
binary_tree_insert_right(root, 128);
root->left->left = binary_tree_node(root->left, 10);
root->right->left = binary_tree_node(root->right, 10);

int is_perfect = binary_tree_is_perfect(root);
printf("Is the tree perfect? %d\n", is_perfect);
```

In this example, the tree is perfect since all leaf nodes are at the same level, and every non-leaf node has exactly two children. The function will return 1 in this case.
---

---
# Task 17: Binary Tree Sibling
============================================

## Description

The `binary_tree_sibling` function finds the sibling of a given node in a binary tree. If the provided node is `NULL` or its parent is `NULL`, the function returns `NULL`. If the node has no sibling, it also returns `NULL`. The sibling is determined based on the parent-child relationship within the binary tree.

## Prototype

```c
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
```

## Parameters

- `node`: A pointer to the node for which you want to find the sibling.

## Return Value

- A pointer to the sibling node if found.
- `NULL` if the node is `NULL`, its parent is `NULL`, or the node has no sibling.

## Examples

```c
#include "binary_trees.h"

int main(void)
{
    binary_tree_t *root;
    binary_tree_t *sibling;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->right = binary_tree_node(root->right, 402);

    binary_tree_print(root);
    sibling = binary_tree_sibling(root->left);
    printf("Sibling of %d: %d\n", root->left->n, sibling->n);
    sibling = binary_tree_sibling(root->right->left);
    printf("Sibling of %d: %d\n", root->right->left->n, sibling->n);
    sibling = binary_tree_sibling(root->left->right);
    printf("Sibling of %d: %d\n", root->left->right->n, sibling->n);
    sibling = binary_tree_sibling(root);
    printf("Sibling of %d: %p\n", root->n, (void *)sibling);
    return (0);
}
```

In this example, the `binary_tree_sibling` function is used to find the sibling of different nodes in a binary tree. The output shows the values of the sibling nodes or `(nil)` if no sibling is found.

## Compilation

Your program should be compiled with the following flags:

```bash
$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 17-main.c 17-binary_tree_sibling.c 0-binary_tree_node.c -o 17-sibling
```

## Execution

Run the compiled program:

```bash
$ ./17-sibling
```
---

---
# Task 18: Binary Tree Uncle
=============================================

## Description

The `binary_tree_uncle` function finds the uncle of a given node in a binary tree. If the provided node is `NULL`, the function returns `NULL`. If the node has no uncle, it also returns `NULL`. The uncle is determined based on the parent and grandparent relationship within the binary tree.

## Prototype

```c
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
```

## Parameters

- `node`: A pointer to the node for which you want to find the uncle.

## Return Value

- A pointer to the uncle node if found.
- `NULL` if the node is `NULL`, or the node has no uncle.

## Examples

```c
#include "binary_trees.h"

int main(void)
{
    binary_tree_t *root;
    binary_tree_t *uncle;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->right = binary_tree_node(root->right, 402);

    binary_tree_print(root);
    uncle = binary_tree_uncle(root->right->left);
    printf("Uncle of %d: %d\n", root->right->left->n, uncle->n);
    uncle = binary_tree_uncle(root->left->right);
    printf("Uncle of %d: %d\n", root->left->right->n, uncle->n);
    uncle = binary_tree_uncle(root->left);
    printf("Uncle of %d: %p\n", root->left->n, (void *)uncle);
    return (0);
}
```

In this example, the `binary_tree_uncle` function is used to find the uncle of different nodes in a binary tree. The output shows the values of the uncle nodes or `(nil)` if no uncle is found.

## Compilation

Your program should be compiled with the following flags:

```bash
$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 18-main.c 18-binary_tree_uncle.c 0-binary_tree_node.c -o 18-uncle
```

## Execution

Run the compiled program:

```bash
$ ./18-uncle
```
---

---
# Task 19: Lowest Common Ancestor
=====================================
## Lowest Common Ancestor

The goal of this task is to implement a function that finds the lowest common ancestor of two nodes in a binary tree.

### Function Signature
```c
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);
```

### Parameters
- `first`: A pointer to the first node.
- `second`: A pointer to the second node.

### Return
- A pointer to the lowest common ancestor node of the two given nodes.
- If no common ancestor is found, the function returns `NULL`.

### Approach
The function traverses the ancestors of the first node and checks if each ancestor is also an ancestor of the second node. The first common ancestor found during this process is returned as the lowest common ancestor. If no common ancestor is found, the function returns `NULL`.

### Example
```c
binary_tree_t *ancestor;

ancestor = binary_trees_ancestor(root->left, root->right);
// ancestor now points to the lowest common ancestor of root->left and root->right
```

### Usage
```c
#include "binary_trees.h"

int main(void)
{
    binary_tree_t *root;

    // Initialize and build the binary tree

    binary_tree_t *ancestor = binary_trees_ancestor(root->left, root->right);
    // Use ancestor as needed

    return (0);
}
```

This function provides a convenient way to find the lowest common ancestor of two nodes in a binary tree, aiding in various tree-related algorithms and applications.
---

---
# Task 20: Levelorder
========================================
## Description
The `binary_tree_levelorder` function traverses a binary tree using level-order traversal, also known as breadth-first traversal. It visits each level of the tree from left to right, starting from the root. At each level, it calls a provided function (`func`) with the value of each node.

## Prototype
```c
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
```

## Parameters
- `tree`: A pointer to the root node of the binary tree to traverse.
- `func`: A pointer to a function that takes an integer parameter. This function will be called for each node, passing the value of the node as an argument.

## Usage
```c
#include "binary_trees.h"

void print_num(int n)
{
    printf("%d\n", n);
}

int main(void)
{
    binary_tree_t *root = binary_tree_node(NULL, 98);
    // Create and configure the binary tree

    binary_tree_levelorder(root, &print_num);
    // Call the binary_tree_levelorder function with the provided print_num function

    // Remember to free the memory allocated for the binary tree
    binary_tree_delete(root);

    return (0);
}
```

## Considerations
- The provided function `func` should be able to handle an integer parameter.
- If either `tree` or `func` is `NULL`, the function does nothing.
- Ensure proper memory management (e.g., freeing memory) after using the function.

## Example
```c
binary_tree_t *root = binary_tree_node(NULL, 98);
// Create and configure the binary tree

binary_tree_levelorder(root, &print_num);
// Output:
// 98

// ... Continue adding nodes to the binary tree and calling binary_tree_levelorder

// Remember to free the memory allocated for the binary tree
binary_tree_delete(root);
```
---

---
# Task 21: Binary Tree Completeness Check
===========================================

## Objective
The objective of this task is to implement a function `binary_tree_is_complete` that checks whether a given binary tree is complete or not.

## Function Signature
```c
int binary_tree_is_complete(const binary_tree_t *tree);
```

## Parameters
- `tree`: Pointer to the root node of the binary tree to be checked.

## Return Value
- Returns 1 if the binary tree is complete.
- Returns 0 otherwise.

## Requirements
- The function should adhere to the specified prototypes and requirements mentioned in the task description.
- Use the provided data structures and types for binary trees.
- The implementation should consider the completeness of the binary tree.

## Examples
For example usage and expected outputs, refer to the provided test cases in the main function.

## Notes
- A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as left as possible.

## Files
- Ensure that the function is correctly implemented in the designated source file.
- Provide a README.md file at the root of the project folder with information about the task, function, and any additional details deemed necessary.

## Testing
- The provided main.c file contains test cases to validate the correctness of the implemented function.
- Compile the code using the specified options and test the program with the given examples.
- Verify that the function works as expected and produces the correct output for various scenarios.

## Submission
- Submit the source code file containing the implementation of the `binary_tree_is_complete` function.
- Ensure that the code adheres to the specified requirements and is well-documented.
- Include the necessary header file with the function prototype.
- Do not include the main.c file in the submission.
- Ensure that the README.md file provides clear and concise information about the task and the implemented function.
---

---
# Task 22: Binary Tree Left Rotation
==================================================

## Objective
The objective of this task is to implement a function `binary_tree_rotate_left` that performs a left rotation on a binary tree.

## Function Signature
```c
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
```

## Parameters
- `tree`: Pointer to the root node of the binary tree to be rotated.

## Return Value
- Returns a pointer to the new root node of the tree after the left rotation.

## Requirements
- The function should adhere to the specified prototypes and requirements mentioned in the task description.
- The left rotation should be performed while maintaining the binary tree properties.

## Examples
For example usage and expected outputs, refer to the provided test cases in the main function.

## Notes
- A left rotation on a binary tree is an operation that preserves the binary search tree properties and performs a leftward rotation of the nodes.

## Files
- Ensure that the function is correctly implemented in the designated source file.
- Provide a README.md file at the root of the project folder with information about the task, function, and any additional details deemed necessary.

## Testing
- The provided main.c file contains test cases to validate the correctness of the implemented function.
- Compile the code using the specified options and test the program with the given examples.
- Verify that the function works as expected and produces the correct output for various scenarios.

## Submission
- Submit the source code file containing the implementation of the `binary_tree_rotate_left` function.
- Ensure that the code adheres to the specified requirements and is well-documented.
- Include the necessary header file with the function prototype.
- Do not include the main.c file in the submission.
- Ensure that the README.md file provides clear and concise information about the task and the implemented function.
---

---
# Task 23: Binary Tree Right Rotation
=================================================

## Objective
The objective of this task is to implement a function `binary_tree_rotate_right` that performs a right rotation on a binary tree.

## Function Signature
```c
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
```

## Parameters
- `tree`: Pointer to the root node of the binary tree to be rotated.

## Return Value
- Returns a pointer to the new root node of the tree after the right rotation.

## Requirements
- The function should adhere to the specified prototypes and requirements mentioned in the task description.
- The right rotation should be performed while maintaining the binary tree properties.

## Examples
For example usage and expected outputs, refer to the provided test cases in the main function.

## Notes
- A right rotation on a binary tree is an operation that preserves the binary search tree properties and performs a rightward rotation of the nodes.

## Files
- Ensure that the function is correctly implemented in the designated source file.
- Provide a README.md file at the root of the project folder with information about the task, function, and any additional details deemed necessary.

## Testing
- The provided main.c file contains test cases to validate the correctness of the implemented function.
- Compile the code using the specified options and test the program with the given examples.
- Verify that the function works as expected and produces the correct output for various scenarios.

## Submission
- Submit the source code file containing the implementation of the `binary_tree_rotate_right` function.
- Ensure that the code adheres to the specified requirements and is well-documented.
- Include the necessary header file with the function prototype.
- Do not include the main.c file in the submission.
- Ensure that the README.md file provides clear and concise information about the task and the implemented function.
---

---
# Task 24: Binary Tree Valid Binary Search Tree Check
=================================================

## Objective
The objective of this task is to implement a function `binary_tree_is_bst` that checks whether a given binary tree is a valid Binary Search Tree (BST).

## Function Signature
```c
int binary_tree_is_bst(const binary_tree_t *tree);
```

## Parameters
- `tree`: Pointer to the root node of the binary tree to be checked.

## Return Value
- Returns 1 if the tree is a valid BST.
- Returns 0 otherwise.
- If tree is NULL, returns 0.

## Requirements
- The function should adhere to the specified prototypes and requirements mentioned in the task description.
- The binary tree must satisfy the properties of a Binary Search Tree.
  - The left subtree of a node contains only nodes with values less than the node’s value.
  - The right subtree of a node contains only nodes with values greater than the node’s value.
  - The left and right subtrees must also be a binary search tree.
  - There must be no duplicate values.

## Examples
For example usage and expected outputs, refer to the provided test cases in the main function.

## Notes
- A Binary Search Tree is a binary tree with the property that each node's value is greater than or equal to all the values in the left subtree and less than or equal to all the values in the right subtree.

## Files
- Ensure that the function is correctly implemented in the designated source file.
- Provide a README.md file at the root of the project folder with information about the task, function, and any additional details deemed necessary.

## Testing
- The provided main.c file contains test cases to validate the correctness of the implemented function.
- Compile the code using the specified options and test the program with the given examples.
- Verify that the function works as expected and produces the correct output for various scenarios.

## Submission
- Submit the source code file containing the implementation of the `binary_tree_is_bst` function.
- Ensure that the code adheres to the specified requirements and is well-documented.
- Include the necessary header file with the function prototype.
- Do not include the main.c file in the submission.
- Ensure that the README.md file provides clear and concise information about the task and the implemented function.
---

---
# Task 25: Binary Search Tree Insertion
===========================================

## Objective
The objective of this task is to implement a function `bst_insert` that inserts a value into a Binary Search Tree (BST).

## Function Signature
```c
bst_t *bst_insert(bst_t **tree, int value);
```

## Parameters
- `tree`: Double pointer to the root node of the BST.
- `value`: Value to store in the node to be inserted.

## Return Value
- Returns a pointer to the created node.
- Returns NULL on failure.
- If the address stored in `tree` is NULL, the created node becomes the root node.

## Requirements
- The function should adhere to the specified prototypes and requirements mentioned in the task description.
- The binary tree must maintain the properties of a Binary Search Tree.
  - The left subtree of a node contains only nodes with values less than the node’s value.
  - The right subtree of a node contains only nodes with values greater than the node’s value.
  - The left and right subtrees must also be a binary search tree.
  - There must be no duplicate values.

## Examples
For example usage and expected outputs, refer to the provided test cases in the main function.

## Notes
- A Binary Search Tree is a binary tree with the property that each node's value is greater than or equal to all the values in the left subtree and less than or equal to all the values in the right subtree.

## Files
- Ensure that the function is correctly implemented in the designated source file.
- Provide a README.md file at the root of the project folder with information about the task, function, and any additional details deemed necessary.

## Testing
- The provided main.c file contains test cases to validate the correctness of the implemented function.
- Compile the code using the specified options and test the program with the given examples.
- Verify that the function works as expected and produces the correct output for various scenarios.

## Submission
- Submit the source code file containing the implementation of the `bst_insert` function.
- Ensure that the code adheres to the specified requirements and is well-documented.
- Include the necessary header file with the function prototype.
- Do not include the main.c file in the submission.
- Ensure that the README.md file provides clear and concise information about the task and the implemented function.
---

---
# Task 26: Binary Search Tree from Array
=========================================

## Objective
The objective of this task is to implement a function `array_to_bst` that builds a Binary Search Tree (BST) from an array of integers.

## Function Signature
```c
bst_t *array_to_bst(int *array, size_t size);
```

## Parameters
- `array`: Pointer to the first element of the array to be converted.
- `size`: Number of elements in the array.

## Return Value
- Returns a pointer to the root node of the created BST.
- Returns NULL on failure.

## Requirements
- The function should adhere to the specified prototypes and requirements mentioned in the task description.
- The binary tree must maintain the properties of a Binary Search Tree.
  - The left subtree of a node contains only nodes with values less than the node’s value.
  - The right subtree of a node contains only nodes with values greater than the node’s value.
  - The left and right subtrees must also be a binary search tree.
  - There must be no duplicate values.

## Examples
For example usage and expected outputs, refer to the provided test cases in the main function.

## Notes
- A Binary Search Tree is a binary tree with the property that each node's value is greater than or equal to all the values in the left subtree and less than or equal to all the values in the right subtree.

## Files
- Ensure that the function is correctly implemented in the designated source file.
- Provide a README.md file at the root of the project folder with information about the task, function, and any additional details deemed necessary.

## Testing
- The provided main.c file contains test cases to validate the correctness of the implemented function.
- Compile the code using the specified options and test the program with the given examples.
- Verify that the function works as expected and produces the correct output for various scenarios.

## Submission
- Submit the source code file containing the implementation of the `array_to_bst` function.
- Ensure that the code adheres to the specified requirements and is well-documented.
- Include the necessary header file with the function prototype.
- Do not include the main.c file in the submission.
- Ensure that the README.md file provides clear and concise information about the task and the implemented function.
---

---
# Task 27: Binary Search Tree Search
====================================

## Objective
The objective of this task is to implement a function `bst_search` that searches for a value in a Binary Search Tree (BST).

## Function Signature
```c
bst_t *bst_search(const bst_t *tree, int value);
```

## Parameters
- `tree`: Pointer to the root node of the BST to search.
- `value`: Value to search for in the tree.

## Return Value
- Returns a pointer to the node containing a value equal to `value`.
- Returns NULL if the value is not found or if `tree` is NULL.

## Requirements
- The function should adhere to the specified prototypes and requirements mentioned in the task description.
- The binary tree must maintain the properties of a Binary Search Tree.
  - The left subtree of a node contains only nodes with values less than the node’s value.
  - The right subtree of a node contains only nodes with values greater than the node’s value.
  - The left and right subtrees must also be a binary search tree.
  - There must be no duplicate values.

## Examples
For example usage and expected outputs, refer to the provided test cases in the main function.

## Notes
- A Binary Search Tree is a binary tree with the property that each node's value is greater than or equal to all the values in the left subtree and less than or equal to all the values in the right subtree.

## Files
- Ensure that the function is correctly implemented in the designated source file.
- Provide a README.md file at the root of the project folder with information about the task, function, and any additional details deemed necessary.

## Testing
- The provided main.c file contains test cases to validate the correctness of the implemented function.
- Compile the code using the specified options and test the program with the given examples.
- Verify that the function works as expected and produces the correct output for various scenarios.

## Submission
- Submit the source code file containing the implementation of the `bst_search` function.
- Ensure that the code adheres to the specified requirements and is well-documented.
- Include the necessary header file with the function prototype.
- Do not include the main.c file in the submission.
- Ensure that the README.md file provides clear and concise information about the task and the implemented function.
---

---
# Task 28: Binary Search Tree Removal
======================================

## Description
The goal of this task is to implement a function `bst_remove` that removes a node with a specified value from a Binary Search Tree (BST). The BST is a binary tree where the left subtree of a node contains only nodes with values less than the node's value, and the right subtree contains only nodes with values greater than the node's value. The `bst_remove` function follows the rules of removing a node from a BST while maintaining its structure.

## Function Signature
```c
bst_t *bst_remove(bst_t *root, int value);
```

### Parameters
- `root`: Pointer to the root node of the BST where the node will be removed.
- `value`: The value to remove from the tree.

### Return
- The function returns a pointer to the new root node of the tree after removing the specified value.

## Implementation
The implementation follows the standard rules for removing a node from a BST:
- If the value to be removed is less than the current node's value, the left subtree is recursively searched.
- If the value is greater, the right subtree is recursively searched.
- If the value is found, the node is removed according to the following cases:
  - If the node has no children or only one child, it is removed directly.
  - If the node has two children, the in-order successor (smallest in the right subtree) is found, and its data is copied to the current node. Then, the in-order successor is recursively removed.

## Usage
The provided `114-main.c` file contains a sample program demonstrating the usage of the `bst_remove` function. The BST is created from an array of values, and nodes are removed one by one using the `bst_remove` function. The resulting BST is printed after each removal to verify the correctness of the removal process.

## Testing
The provided test case uses the `binary_tree_print` function to visualize the structure of the BST before and after each removal. Additionally, the program utilizes Valgrind to check for memory leaks, ensuring the correct deallocation of memory.

## Compilation
To compile the program, the following command can be used:
```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 114-bst_remove.c 114-main.c 112-array_to_bst.c 111-bst_insert.c 0-binary_tree_node.c 3-binary_tree_delete.c -o 114-bst_rm
```

## Execution
To execute the compiled program, use the following command:
```bash
./114-bst_rm
```

The program will display the initial and modified BST structures after each removal, and Valgrind can be used to ensure there are no memory leaks.

## Expected Output
The expected output includes the visualization of the BST structure before and after each removal, along with a confirmation of successful memory deallocation.

```plaintext
                                     .------------(079)-------.
                 .-----------------(047)-------.         .--(087)--.
       .-------(021)-------.              .--(068)     (084)     (091)-------.
  .--(002)--.         .--(032)--.       (062)                           .--(098)
(001)     (020)     (022)     (034)                                   (095)
Removed 79...
                                     .------------(084)--.
                 .-----------------(047)-------.       (087)--.
       .-------(022)--.              .--(068)          (091)-------.
  .--(002)--.       .--(032)--.       (062)                      .--(098)
(001)     (020)     (034)          (095)
Removed 21...
                                .------------(084)--.
                 .------------(047)--.       (087)--.
       .-------(022)--.            (062)          (091)-------.
  .--(002)--.       (032)--.                             .--(098)
(001)     (020)     (034)                         (095)
Removed 68...
                                .-------(084)--.
                 .------------(047)--.       (087)--.
       .-------(022)--.            (062)          (091)-------.
  .--(002)--.       (032)--.                             .--(098)
(001)     (020)     (034)                         (095)
```

The output confirms the successful removal of nodes with the specified values and the maintenance of the BST properties. The memory deallocation is also verified using Valgrind.

**Note:** The actual output may vary based on the specific implementation and the platform/compiler used.
---

---
# Task 30: Big O of BST
======================================

The average time complexities for operations on a Binary Search Tree (BST) are as follows:

- **Inserting the value n:**
  - Average Time Complexity: O(log n)
  - Explanation: In a well-balanced BST, the height is logarithmic with respect to the number of nodes. Hence, the average time complexity for insertion is O(log n).

- **Removing the node with the value n:**
  - Average Time Complexity: O(log n)
  - Explanation: Similar to insertion, the average time complexity for removing a node in a well-balanced BST is O(log n).

- **Searching for a node in a BST of size n:**
  - Average Time Complexity: O(log n)
  - Explanation: The average time complexity for searching in a well-balanced BST is also O(log n) because, at each comparison, the search space is reduced by half.

It's important to note that these time complexities assume that the BST is well-balanced. In the worst-case scenario, where the BST is degenerate (essentially a linked list), the time complexities for these operations could degrade to O(n). However, the average-case analysis considers a balanced scenario.
---

---
## Task 30 - Binary Tree is AVL
===========================================

### Objective
The goal of this task is to determine whether a given binary tree is a valid AVL (Adelson-Velsky and Landis) tree. An AVL tree is a type of self-balancing binary search tree where the difference in heights between the left and right subtrees of any node is at most 1, and both the left and right subtrees are also AVL trees.

### Solution
To solve this task, we implement the `binary_tree_is_avl` function. This function takes a pointer to the root node of a binary tree and recursively checks if it satisfies the properties of an AVL tree. The key steps include:

1. Calculate the height of the left and right subtrees.
2. Check if the difference in height is greater than 1; if so, the tree is not AVL.
3. Recursively check if both the left and right subtrees are AVL trees.

### Example
```c
binary_tree_t *root = basic_tree();

binary_tree_print(root);
int avl = binary_tree_is_avl(root);
printf("Is %d avl: %d\n", root->n, avl);
```

In this example, we create a basic binary tree and use the `binary_tree_is_avl` function to check if it is a valid AVL tree. The result is printed, indicating whether the tree satisfies the AVL tree properties.

### Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 120-binary_tree_is_avl.c 0-binary_tree_node.c 120-main.c -o 120-is_avl
```

### Execution
```bash
./120-is_avl
```

### Expected Output
```
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)
Is 98 avl: 1
Is 12 avl: 1
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (097)     (402)
Is 98 avl: 0
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)--.
                              (430)
Is 98 avl: 0
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)-------.
                                .--(430)
                              (420)
Is 98 avl: 0
```

This demonstrates the functionality of the `binary_tree_is_avl` function in checking the validity of AVL trees.
---

---
## Task 31 - AVL Tree Insertion
========================================

### Objective
The objective of this task is to implement a function that inserts a value into an AVL (Adelson-Velsky and Landis) Tree while maintaining its balance.

### Solution
To solve this task, we implement the `avl_insert` function. This function takes a double pointer to the root node of an AVL tree and a value to be inserted. It inserts the value into the AVL tree, ensuring that the resulting tree is a balanced AVL tree. The key steps include:

1. Perform a regular BST (Binary Search Tree) insert.
2. Update the height of the current node.
3. Calculate the balance factor of the current node.
4. Perform the necessary rotations (left, right, left-right, right-left) to restore balance.
5. Update the height of the affected nodes after rotations.

### Example
```c
avl_t *root = NULL;
avl_t *node;

node = avl_insert(&root, 98);
printf("Inserted: %d\n", node->n);
binary_tree_print(root);
```

In this example, we insert a value into an AVL tree using the `avl_insert` function. The resulting tree is then printed, showcasing the balancing of the AVL tree.

### Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 121-avl_insert.c 121-main.c 14-binary_tree_balance.c 103-binary_tree_rotate_left.c 104-binary_tree_rotate_right.c 0-binary_tree_node.c -o 121-avl_insert
```

### Execution
```bash
./121-avl_insert
```

### Expected Output
```
Inserted: 98
(098)

Inserted: 402
(098)--.
     (402)

Inserted: 12
  .--(098)--.
(012)     (402)

Inserted: 46
  .-------(098)--.
(012)--.       (402)
     (046)

Inserted: 128
  .-------(098)-------.
(012)--.         .--(402)
     (046)     (128)

Inserted: 256
  .-------(098)-------.
(012)--.         .--(256)--.
     (046)     (128)     (402)

Inserted: 512
  .-------(098)-------.
(012)--.         .--(256)--.
     (046)     (128)     (402)--.
                              (512)

Inserted: 50
       .-------(098)-------.
  .--(046)--.         .--(256)--.
(012)     (050)     (128)     (402)--.
                                   (512)
```

This demonstrates the functionality of the `avl_insert` function in maintaining the balance of an AVL tree after insertion.
---

---

