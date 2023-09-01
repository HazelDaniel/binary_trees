#include "binary_trees.h"
#include "3-binary_tree_delete.c"


void max_heapify(binary_tree_t *root, binary_tree_t *curr_root);


/**
 * heap_to_sorted_array - a function that
 * returns the array version of a max heap
 * @heap: the pointer to the root node
 * of a max heap
 * @size: the size of the array
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int front = 0, rear = 0, i = 0, *res, tmp;
	heap_t *current, *tree_queue[1000];

	*size = 0;
	if (!heap)
		return (NULL);

	tree_queue[rear++] = heap;

	while (front < rear)
	{
		current = tree_queue[front++];

		if (current->left)
			tree_queue[rear++] = current->left;
		if (current->right)
			tree_queue[rear++] = current->right;
		i++;
	}

	*size = i;
	i--;
	res = malloc(*size * sizeof(int));
	for (; i >= 0 && tree_queue[i]; i--)
	{
		res[i] = heap_extract(&heap);
	}
	for (i = 0; (size_t)i < (*size >> 1); i++)
	{
		tmp = res[i];
		res[i] = res[*size - 1 - i];
		res[*size - 1 - i] = tmp;
	}

	return (res);
}
