#include "binary_trees.h"
#include "112-array_to_bst.c"



/**
 * sorted_array_to_avl - a function that returns
 * the avl version of a sorted array
 * @array: the array to be converted
 * @size: the size of the array
 * Return: the root node of the new avl tree
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{

	return (array_to_bst(array, size));
}
