#include "binary_trees.h"

/**
 * find_successor - finds the in-order successor of a node
 * @node: pointer to the node for which to find the successor
 * Return: pointer to the in-order successsor node
 */
bst_t *find_successor(bst_t *node)
{
	bst_t *successor = node->right;

	while (successor && successor->left)
		successor = successor->left;
	return (successor);
}

/**
 * bst_remove - remove a node from a binary search tree
 * @root: pointer to the root node of the tree where the node
 * will be removed
 * @value: value to remove in the tree
 * Return: pointer to the new rot node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmpo;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			tmpo = root->right;
			free(root);
			return (tmpo);
		}
		else if (!root->right)
		{
			tmpo = root->left;
			free(root);
			return (tmpo);
		}
		tmpo = find_successor(root);
		root->n = tmpo->n;
		root->right = bst_remove(root->right, tmpo->n);
	}
	return (root);
}
