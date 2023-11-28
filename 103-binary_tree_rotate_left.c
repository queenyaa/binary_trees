#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *n_root;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	n_root = tree->right;
	tree->right = n_root->left;

	if (n_root->left != NULL)
		n_root->left->parent = tree;

	n_root->parent = tree->parent;

	if (tree->parent == NULL)
		n_root->parent = NULL;
	else if (tree == tree->parent->left)
		tree->parent->left = n_root;
	else
		tree->parent->right = n_root;
	n_root->left = tree;
	tree->parent = n_root;

	return (n_root);
}
