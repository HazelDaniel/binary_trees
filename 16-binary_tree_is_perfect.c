#include "binary_trees.h"
#include <stdio.h>

int bin_tree_is_perfect(const binary_tree_t *tree, int reset);

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
 * bin_T_height - a procedure to generate the
 * height of the binary tree for the main function
 * @tree: the pointer to the root node of the binary Tree
 * Return: height
 **/
static size_t bin_T_height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	l_height = bin_T_height(tree->left);
	r_height = bin_T_height(tree->right);

	return ((max(l_height, r_height)) + 1);
}

/**
 * binary_tree_balance - a function that
 * calculates the balance factor of a tree/sub-tree
 * @tree: a pointer to the root node of the tree/sub-tree
 * Return: the balance factor
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	l_height = bin_T_height(tree->left);
	r_height = bin_T_height(tree->right);

	return ((int)(l_height - r_height));
}


/**
 * binary_tree_is_perfect - a function that returns
 * whether a binary tree is perfect or not
 * @tree: the pointer to the root node of the binary
 * tree
 * description: one way to find out is to
 *             add all the total balance factors of
 *             all nodes in the tree
 * Return: void
 **/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int res_bool;
	res_bool = bin_tree_is_perfect(tree, 0);
	(void)bin_tree_is_perfect(NULL, 1);
	return (res_bool);
}

/**
 * bin_tree_is_perfect - a function that returns
 * whether a binary tree is perfect or not
 * @tree: the pointer to the root node of the binary
 * tree
 * description: one way to find out is to
 *             add all the total balance factors of
 *             all nodes in the tree
 * Return: void
 **/
int bin_tree_is_perfect(const binary_tree_t *tree, int reset)
{
	int is_perfect_here = 1;
	static int count = 0;

	if (reset)
	{
		count = 0;
		return (count);
	}

	if (!tree)
	{
		if (!count)
			return (0);
		else
		{
			return (1);
		}
	}

	if (binary_tree_balance(tree) == 0)
			is_perfect_here = 1;
	else
		is_perfect_here = 0;


	count++;
	is_perfect_here = (is_perfect_here &&
		bin_tree_is_perfect(tree->left, 0) &&
		bin_tree_is_perfect(tree->right, 0));

	return (is_perfect_here);
}
