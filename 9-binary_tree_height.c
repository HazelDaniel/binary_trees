#include "binary_trees.h"
#include <stdio.h>

size_t bin_tree_height(const binary_tree_t *tree);
/**
 * max - a function that returns the maximum between two
 * unsigned integers
 * @a: operand a
 * @b: operand b
 * Return: maximum
 **/
size_t max(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	return (b);
}

/**
 * binary_tree_height - a function that returns the height
 * of a binary tree
 * @tree: the pointer to the root node of the binary Tree
 * Return: height
 **/
size_t binary_tree_height(const binary_tree_t *tree)
{
	return (bin_tree_height(tree) - 1);
}

size_t bin_tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	l_height = bin_tree_height(tree->left);
	r_height = bin_tree_height(tree->right);

	return ((max(l_height, r_height)) + 1);
}
