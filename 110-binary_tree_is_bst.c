#include "binary_trees.h"


/**
 * get_max - a function that gets the maximum value in
 * a sut-tree of a binary tree
 * @root: the root of the sub-tree
 * @max_addr: pointer to the value to be updated
 * Return: void
 **/
void get_max(binary_tree_t *root, int *max_addr)
{
	if (!root)
		return;

	if (root->n > *max_addr)
		*max_addr = root->n;

	get_max(root->right, max_addr);
	get_max(root->left, max_addr);
}

/**
 * get_min - a function that gets the minimum value in
 * a sut-tree of a binary tree
 * @root: the root of the sub-tree
 * @min_addr: pointer to the value to be updated
 * Return: void
 **/
void get_min(binary_tree_t *root, int *min_addr)
{
	if (!root)
		return;

	if (root->n < *min_addr)
		*min_addr = root->n;

	get_min(root->right, min_addr);
	get_min(root->left, min_addr);
}

/**
 * is_bst - a function that checks if a sub-tree
 * of height 1 is a binary tree given the root
 * @root: the root of the sub-tree
 * Return: whether the sub-tree is a binary tree
 * or not
 **/
int is_bst(binary_tree_t *root)
{
	int maximum = 0;
	int minimum = 0;

	if (!root)
		return (0);


	maximum = root->n;
	minimum = root->n;

	get_max(root->left, &maximum);
	if (maximum > root->n)
		return (0);
	get_min(root->right, &minimum);
	if (minimum < root->n)
		return (0);

	return (1);
}

/**
 * binary_tree_is_bst - a function that returns whether a binary
 * tree is a binary search tree
 * @tree: the pointer to the root node of the binary
 * tree
 * Return: whether a binary tree is a BST
 **/
int binary_tree_is_bst(const binary_tree_t *tree)
{

	return (is_bst((binary_tree_t *)tree));
}
