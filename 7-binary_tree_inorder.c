#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to the functio call for each node
 * the value in the node must be passed as a parameter to this function
 * If tree or func is NULL, do nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* traverse the left subtree in in-order */
	binary_tree_inorder(tree->left, func);
	/* call the function to the current node */
	func(tree->n);
	/* traverse the right subtree in in-order */
	binary_tree_inorder(tree->right, func);
}
