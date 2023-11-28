#include "binary_trees.h"

/**
 * h_len - measures the height of the binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: if tree is NULL, your function must return 0, else
 * return h_len
 */
size_t h_len(const binary_tree_t *tree)
{
	size_t l_len = 0, r_len = 0;

	if (tree != NULL)
	{
		l_len = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r_len = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l_len > r_len) ? 1 : r_len);
	}
	return (0);
}

/**
 * b_lanc - measures the balance of the tree
 * @tree: pointer to the root node of the tree to measure the balance
 * Return: if tree is NULL, return 0, else return balance factor
 */
int b_lanc(const binary_tree_t *tree)
{
	return (tree != NULL ? h_len(tree->left) - h_len(tree->right) : 0);
}

/**
 * avl_in_recur - inserts value into AVL tree recursively
 * @tree: double pointer to theroot node of tree
 * @parent: parent of node of the current working node
 * @nw: new double pointer to store
 * @value: value to insert into tree
 * Return: pointer to new root after insertion or NULL on failure
 */
avl_t *avl_in_recur(avl_t **tree, avl_t *parent,
		avl_t **nw, int value)
{
	int b_fact;

	if (*tree == NULL)
		return (*nw = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_in_recur(&(*tree)->left, *tree,
				nw, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_in_recur(&(*tree)->right, *tree,
				nw, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);
	b_fact = b_lanc(*tree);
	if (b_fact > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (b_fact < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (b_fact > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b_fact < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - inserts a value into AVL tree
 * @tree: double pointer to the root node of the AVL tree
 * @value:; value to insert into the AVL tere
 * Return: pointer to the inserted node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *nw = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_in_recur(tree, *tree, &nw, value);
	return (nw);
}
