#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right rotation on a binary tree
 * @tree: pointer to the root node fo the tree to rotate
 * Return: pointer to the new root node fothe tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *n_root;

	if (tree == NULL || tree->left == NULL)
		return (tree);
	n_root = tree->left;
	tree->left = n_root->right;

	if (n_root->right != NULL)
		n_root->right->parent = tree;

	n_root->parent = tree->parent;

	if (tree->parent == NULL)
		n_root->parent = NULL;
	else if (tree == tree->parent->right)
		tree->parent->right = n_root;
	else
		tree->parent->left = n_root;
	n_root->right = tree;
	tree->parent = n_root;

	return (n_root);
}
