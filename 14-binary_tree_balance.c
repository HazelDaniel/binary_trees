#include "binary_trees.h"
static size_t bin_T_height(const binary_tree_t *tree);
#include "9-binary_tree_height.c"


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
 * bin_tree_height - a procedure to generate the
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
