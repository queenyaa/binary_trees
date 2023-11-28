#include "binary_trees.h"

/**
 * binary_tree_is_full - check if a binary tree is full
 * @tree: pointer to the root node of the tree
 * Return: 1 fif tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int v, x, w;

	if (tree == NULL)
		return (0);

	/* check if the node is a leaf */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* check if both subtrees are full */
	if (tree->left && tree->right)
	{
		v = binary_tree_is_full(tree->left);
		w = binary_tree_is_full(tree->right);
		x = v && w;
		return (x);
	}
	/* if one subtree is empty and other is not, tree is not balance */
	return (0);
}
