#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue = NULL, *current;
	int front = 0, rear = 0;
	int null_seen = 0;

	if (tree == NULL)
		return (0);
	queue = malloc(sizeof(binary_tree_t *) * 1000);
	if (queue == NULL)
		return (0);
	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		current = queue[front++];
		if (current == NULL)
			null_seen = 1;
		else if (null_seen)
		{
			free(queue);
			return (0);
		}
		else
		{
			queue = realloc(queue, sizeof(binary_tree_t *)
					* (rear + 2));
			if (queue == NULL)
				return (0);
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}
	free(queue);
	return (1);
}
