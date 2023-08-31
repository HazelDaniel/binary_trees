#include "binary_trees.h"


/**
 * array_to_heap - a function that returns
 * the max-heap version of an array
 * @array: the input array
 * @size: the size of the given array
 * Return: the pointer to the root node
 * of the newly created heap
 **/
heap_t *array_to_heap(int *array, size_t size)
{
	int i = 0;
	heap_t *root = NULL;

	for (; (size_t)i < size; i++)
		heap_insert(&root, array[i]);
	return (root);
}
