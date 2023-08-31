#include "binary_trees.h"


/**
 * bst_search - a function that does
 * an item lookup in a binary search tree
 * @tree: the pointer to the root node of
 * the binary search tree
 * @value: the value of the node to search for
 * Return: the node
 *
 **/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value > tree->n)
	{
		return (bst_search(tree->right, value));
	}
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (((bst_t *)tree));

	return (NULL);
}

