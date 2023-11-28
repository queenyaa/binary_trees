#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in
 * a binary tree
 * @tree: pointer to the root node of the tree to count the number
 * Return: Number of nodes with at least 1 child, or 0 otherwise
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int v, w, sum;

	if (tree == NULL)
		return (0);

	/* count nodes recursively */
	if (tree->left != NULL || tree->right != NULL)
	{
		v = binary_tree_nodes(tree->left);
		w = binary_tree_nodes(tree->right);
		sum = 1 + v + w;
		return (sum);
	}

	return (0);
}
