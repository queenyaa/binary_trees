#include "binary_trees.h"

/**
 * binary_tree_delete - deletes a binary tree
 * @tree: pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}

/**
 * bst_free - free a binary search tree
 * @tree: pointer to the root node of the BST
 */
void bst_free(bst_t *tree)
{
	binary_tree_delete(tree);
}

/**
 * array_to_bst - builds a binary search tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created BST, or
 * NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t x;

	if (array == NULL || size == 0)
		return (NULL);
	for (x = 0; x < size; x++)
	{
		if (bst_insert(&root, array[x]) == NULL)
		{
			bst_free(root);
			return (NULL);
		}
	}
	return (root);
}
