#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: pointer to the created nod, NULL otherwise
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *n_node;

	if (parent == NULL)
		return (NULL);

	n_node = binary_tree_node(parent, value);
	if (n_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		n_node->left = parent->left;
		n_node->left->parent = n_node;
	}
	parent->left = n_node;

	return (n_node);
}
