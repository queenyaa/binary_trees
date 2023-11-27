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

