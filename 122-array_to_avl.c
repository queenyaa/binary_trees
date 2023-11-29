#include "binary_trees.h"

/**
 * comp_int - compar function for qsort
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 * Return: result of the comparison
 */
int comp_int(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

/**
 * array_to_avl - buildds an AVL tree from an array
 * @array: pointer to the first element of the array
 * @size: number of the elements in the array
 * Return: pointer to the root node of hte created AVL tree
 * or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t x;

	if (array == NULL || size == 0)
		return (NULL);

	qsort(array, size, sizeof(int), comp_int);
	for (x = 0; x < size; x++)
	{
		/** for (y = 0; y < x; y++)
		 * {
		 * 	if (array[y] == array[x])
		 * 		break;
		 * }
		 * if (y == x)
		 * {
		 */
		if (avl_insert(&root, array[x]) == NULL)
				return (NULL);
		/* } */
	}
	return (root);
}
