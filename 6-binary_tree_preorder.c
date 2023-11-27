#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through a binary tree using pre-order
 * traversal
 * @tree: pointer to the roor node of the tree to traverse
 * @func: pointer to a function to call for each node
 * the value in the node must be passed as a parameter to this
 * function
 * If tree or func is NULL, do nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* call function for the current node */
	func(tree->n);
	/* traverse the left subtree in pre-order */
	binary_tree_preorder(tree->left, func);
	/* traverse the right subtree in pre-order */
	binary_tree_preorder(tree->right, func);
}
