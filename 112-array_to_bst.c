#include "binary_trees.h"


bst_t *arr_to_bst(int *arr, size_t low, size_t high, bst_t *tree, size_t size);
/**
 * part_hoare - a function that partitions an array
 * based on the hoare partition scheme
 * @array: the input array
 * @low: the starting index
 * @high: the last index
 * Return: int
 **/
int part_hoare(int *array, int low, int high)
{
	int i = low, j = high + 1, pivot_index = low,
	tmp;


	while (i < j)
	{
		do {
			i++;
		} while (array[i] < array[pivot_index]);

		do {
			j--;
		} while (array[j] > array[pivot_index]);

		if (i <= j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		else
		{
			tmp = array[pivot_index];
			array[pivot_index] = array[j];
			array[j] = tmp;
			break;
		}
	}
	return (j);
}

/**
 * hoare_sort - a function that sorts an input array
 * using quick sort and hoare sort partitioning scheme
 * @array: the input array
 * @low: the lowest index
 * @high: the last index
 * Return: void
 **/
void hoare_sort(int *array, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = part_hoare(array, low, high);
		hoare_sort(array, low, pivot_index - 1);
		hoare_sort(array, pivot_index + 1, high);
	}
}

/**
 * quick_sort_hoare - a function that sorts
 * an input array using quick sort algorithm
 * and a hoare partitioning scheme
 * @array: an input array
 * @size: the size of the array - N
 * Return: void
 **/
void quick_sort_hoare(int *array, size_t size)
{
	if (size > 1)
		hoare_sort(array, 0, size - 1);
}

/**
 * array_to_bst - a function that converts an array
 * into a binary search tree
 * @array: the input array
 * @size: the number of elements in the array
 * Return: the pointer to the root node of
 * the binary search tree
 **/
bst_t *array_to_bst(int *array, size_t size)
{
	int *tmp_array = malloc(size * sizeof(int)), i;
	bst_t *res_tree = NULL;

	if (!tmp_array)
		return (NULL);
	for (i = 0; i < (int)size; i++)
		tmp_array[i] = array[i];

	quick_sort_hoare(tmp_array, size);
	res_tree = (arr_to_bst(tmp_array, 0, size - 1, NULL, size));

	free(tmp_array);

	return (res_tree);
}

/**
 * arr_to_bst - a function that converts an array
 * into a binary search tree
 * @arr: the input array
 * @low: the starting index of the operation
 * @high: the stoping index of the operation
 * @tree: the pointer to the last root node
 * @size: the number of nodes in the tree
 * in the recursion tree
 * Return: the pointer to the root node of
 * the binary search tree
 **/
bst_t *arr_to_bst(int *arr, size_t low, size_t high, bst_t *tree, size_t size)
{
	size_t mid = low + ((high - low) >> 1);

	if (!arr || high <= low)
	{
		if (high == size - 1)
			return (binary_tree_node(NULL, arr[high]));
		return (NULL);
	}

	tree = binary_tree_node(NULL, arr[mid]);

	tree->left = arr_to_bst(arr, low, mid, tree->left, size);
	if (tree->left)
	{
		tree->left->parent = tree;
		if (tree->left->n >= tree->n)
			return (0);
	}
	tree->right = arr_to_bst(arr, mid + 1, high, tree->right, size);
	if (tree->right)
	{
		tree->right->parent = tree;
		if (tree->right->n <= tree->n)
			return (0);
	}


	return (tree);
}
