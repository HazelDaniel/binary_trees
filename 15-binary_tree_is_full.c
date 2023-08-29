#include "binary_trees.h"
#include "14-binary_tree_balance.c"
#include <stdio.h>


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
	int is_full_here = 0;

	if (!tree)
		return (0);
	if (is_leaf(tree))
	{
		if (!tree->parent)
			return (1);
		return (0);
	}
	if (!has_even_children(tree))
	{
		is_full_here = 1;
	}
	else
	{
		is_full_here += binary_tree_is_full(tree->left);
		is_full_here += binary_tree_is_full(tree->right);
	}
	return (is_full_here == 0);
}
