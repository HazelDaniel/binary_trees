#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
#include <limits.h>


int is_max_heap_naive(const binary_tree_t *tree);
/**
 * get_max - a function that gets the maximum value in
 * a sub-tree of a binary tree
 * @root: the root of the sub-tree
 * @max_addr: pointer to the value to be updated
 * Return: whether there are duplicates or not
 **/
int get_max(binary_tree_t *root, int *max_addr)
{
	int bool = 1;

	if (!root)
		return (1);

	if (root->n > *max_addr)
		*max_addr = root->n;
	if (root->n == *max_addr)
		return (0);

	bool = bool && get_max(root->right, max_addr);
	bool = bool && get_max(root->left, max_addr);

	return (bool);
}

/**
 * binary_tree_is_heap - a function that checks if a binary tree
 * is a max heap.
 * @tree: the pointer to the root node of the tree
 * Description: a max heap must be a binary tree
 * that satisfies these two extra properties:
 *         1. it is complete
 *         2. the root node of every sub-tree is the
 *         maximum of its sub-tree
 * Return: whether it is a max heap or not
 *
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int is_satisfied = 1;

	is_satisfied = is_satisfied && binary_tree_is_complete(tree);
	is_satisfied = is_satisfied && is_max_heap_naive(tree);

	return (is_satisfied);
}

/**
 * is_max_heap_naive - a function that checks if a binary tree
 * is a max heap without checking if it's complete
 * @tree: the pointer to the root node of the tree
 * Description: a max heap must be a binary tree
 * that satisfies these two extra properties:
 *         1. it is complete
 *         2. the root node of every sub-tree is the
 *         maximum of its sub-tree
 * Return: whether it is a max heap or not
 **/
int is_max_heap_naive(const binary_tree_t *tree)
{
	int is_satisfied = 1, max_value = INT_MIN;

	if (!tree)
		return (1);
	(void)get_max(tree->left, &max_value);
	if (max_value > (tree->n))
		is_satisfied = 0;
	(void)get_max(tree->right, &max_value);
	if (max_value > (tree->n))
		is_satisfied = 0;


	is_satisfied = is_satisfied && is_max_heap_naive(tree->left);
	is_satisfied = is_satisfied && is_max_heap_naive(tree->right);

	return (is_satisfied);
}
