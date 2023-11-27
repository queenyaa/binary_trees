#include "binary_trees.h"

/*
 * binary_tree_insert_right - Inserts a node as the right-child of another
 * node
 * @parent: pointer to the node to insert the right-child in
 * @value: value t ostore in the new node
 * Return: pointer to the created node, NULL otherwise
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *n_node;

	if (parent == NULL)
		return (NULL);

	n_node = binary_tree_node(parent, value);
	if (n_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		n_node->right = parent->right;
		n_node->right->parent = n_node;
	}
	parent->right = n_node;
	return (n_node);
}
