#include "binary_trees.h"

/**
 * max - finds the maximum of two numbers
 * @a: first number
 * @b: second number
 * Return: maximum of a and b
 */
size_t max(size_t a, size_t b)
{
	return (a > b ? a : b);
}

/**
 * height - measures the height of the binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t l_height, r_height, diff;

	if (tree == NULL)
		return (0);

	l_height = height(tree->left);
	r_height = height(tree->right);
	diff = l_height > r_height ? l_height - r_height : r_height - l_height;

	if (diff > 1)
		return (0);

	if (!binary_tree_is_avl(tree->left) ||
			!binary_tree_is_avl(tree->right))
		return (0);
	return (1);
}
