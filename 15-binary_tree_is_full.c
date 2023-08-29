#include "binary_trees.h"
#include "14-binary_tree_balance.c"
#include <stdio.h>


int bin_tree_is_full(const binary_tree_t *tree, int reset);

/**
 * is_leaf - a function that returns whether
 * a node is a leaf
 * @node: the node to check against
 * Return: boolean
 **/
int is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return ((!(node->left || node->right)));
}

/**
 * has_even_children - a function that returns whether
 * a node has two or zero children
 * @node: the node to check against
 * Return: boolean
 **/
int has_even_children(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return ((node->left && node->right) || !(node->left || node->right));
}

/**
 * binary_tree_is_full - a function that returns
 * whether a binary tree is full or not
 * @tree: the pointer to the root node of the binary
 * tree
 * description: one way to find out is to
 *             check if all nodes in the
 *             tree have two or zero children
 * Return: void
 **/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int res_bool;

	res_bool = bin_tree_is_full(tree, 0);
	(void)bin_tree_is_full(NULL, 1);
	return (res_bool);
}

/**
 * bin_tree_is_full - a function that returns
 * whether a binary tree is full or not
 * @tree: the pointer to the root node of the binary
 * @reset: this is to add state to the function. an augmentation
 * added to provide correct output in an edge-case
 * tree
 * description: one way to find out is to
 *             add all the total balance factors of
 *             all nodes in the tree
 * Return: void
 **/
int bin_tree_is_full(const binary_tree_t *tree, int reset)
{
	int is_full_here = 1;
	static int count;

	if (reset)
	{
		count = 0;
		return (count);
	}

	if (!tree)
	{
		if (!count)
			return (0);
		return (1);
	}

	if (has_even_children(tree) == 1)
		is_full_here = 1;
	else
		is_full_here = 0;

	count++;
	is_full_here = (is_full_here && bin_tree_is_full(tree->left, 0)
	&& bin_tree_is_full(tree->right, 0));

	return (is_full_here);
}
