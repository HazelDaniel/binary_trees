#include "binary_trees.h"
#include <stdlib.h>
#include <limits.h>


void max_heapify(binary_tree_t *root, binary_tree_t *curr_root);

/**
 * heap_extract - a function that "pops" the root node
 * of a max heap while maintaining the structural integrity
 * @root: the address of the root node
 * of the binary heap
 * Return: whether you suceeded or not
 **/
int heap_extract(heap_t **root)
{
	int value, front = 0, rear = 0, length = 0, tmp;
	heap_t *current = NULL, *tree_queue[1000], *sentinel;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	tree_queue[rear++] = *root;
	while (front < rear)
	{
		current = tree_queue[front++];
		if (current->left)
			tree_queue[rear++] = current->left;
		if (current->right)
			tree_queue[rear++] = current->right;
		length++;
	}
	sentinel = tree_queue[length - 1];
	tmp = sentinel->n;
	sentinel->n = value;
	((*root)->n) = tmp;
	max_heapify(*root, *root);

	if (sentinel->parent)
	{
		if (sentinel == sentinel->parent->right)
			sentinel->parent->right = NULL;
		else
			sentinel->parent->left = NULL;
	}
	free(sentinel);

	return (value);
}
