#include "binary_trees.h"

/**
 * enqueue - enqueues a new node with data
 * @queue: pointer to the queue
 * @data: data of the new node
 */
void enqueue(queue_t **queue, const binary_tree_t *data)
{
	queue_node_t *n_node = malloc(sizeof(queue_node_t));

	if (n_node == NULL)
		return;

	n_node->data = data;
	n_node->next = NULL;

	if (*queue == NULL)
	{
		*queue = malloc(sizeof(queue_t));
		if (*queue == NULL)
		{
			free(n_node);
			return;
		}
		(*queue)->front = (*queue)->rear = n_node;
	}
	else
	{
		(*queue)->rear->next = n_node;
		(*queue)->rear = n_node;
	}
}

/**
 * dequeue - dequeues a node from the queue
 * @queue: pointer to the queue
 * Return: dequeued node, or NULL if the queue is empty
 */
const binary_tree_t *dequeue(queue_t **queue)
{
	queue_node_t *front_node = (*queue)->front;
	const binary_tree_t *data = front_node->data;

	if ((*queue) == NULL || (*queue)->front == NULL)
	{
		return (NULL);
	}

	(*queue)->front = front_node->next;
	free(front_node);

	if ((*queue)->front == NULL)
	{
		free(*queue);
		*queue = NULL;
	}
	return (data);
}

/**
 * free_queue - frees the queue and its nodes
 * @queue: pointer to the queue
 */
void free_queue(queue_t **queue)
{
	if (queue == NULL || *queue == NULL)
		return;
	while ((*queue)->front != NULL)
		dequeue(queue);
	free(*queue);
	*queue = NULL;
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * levelorder
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node. the value
 * in the node must be passed as a parameter to this function
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;
	const binary_tree_t *current = NULL;

	if (tree == NULL || func == NULL)
		return;
	/* create a queue for the level-order traversal */
	enqueue(&queue, tree);
	/* traverse the binary tree level by level */
	while (queue != NULL && (current = dequeue(&queue)) != NULL)
	{
		func(current->n);

		if (current->left != NULL)
			enqueue(&queue, current->left);
		if (current->right != NULL)
			enqueue(&queue, current->right);
	}

	/* free the queue */
	free_queue(&queue);
}
