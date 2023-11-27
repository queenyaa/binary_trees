#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: the number of leaves in the tree, or 0 if otherwise
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int v;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	v = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
	return (v);
}
