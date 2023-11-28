#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height = binary_tree_height(tree->left);
	size_t r_height = binary_tree_height(tree->right);
	int v;

	if (tree == NULL)
		return (0);

	v = (l_height > r_height ? l_height : r_height);
	return (1 + v);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	int v, w;

	if (tree == NULL)
		return (0);

	v = (1 + binary_tree_size(tree->left));
	w = binary_tree_size(tree->right);

	return (v + w);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int a, b;
	size_t l_size = binary_tree_size(tree->left);
	size_t r_size = binary_tree_size(tree->right);

	if (tree == NULL)
		return (0);

	a = binary_tree_size(tree->left);
	b = binary_tree_size(tree->right);

	return (a == b && l_size == r_size);
}
