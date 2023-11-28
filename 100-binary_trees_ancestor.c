#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of
 * two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of
 * the two nodes or NULL if no common ancester found
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first,
		const binary_tree_t *second
		)
{
	const binary_tree_t *tmpo1, *tmpo2;

	if (!first || !second)
		return (NULL);

	tmpo1 = first;
	while (tmpo1)
	{
		tmpo2 = second;
		while (tmpo2)
		{
			if (tmpo1 == tmpo2)
				return ((binary_tree_t *)tmpo1);
			tmpo2 = tmpo2->parent;
		}
		tmpo1 = tmpo1->parent;
	}
	return (NULL);
}
