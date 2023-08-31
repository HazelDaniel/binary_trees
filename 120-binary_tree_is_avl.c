#include "binary_trees.h"
#include "limits.h"


int is_avl(const binary_tree_t *tree, int low, int high);

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
 * is_avl - a function that checks if a tree is an avl tree
 * @tree: A pointer to the root node of the tree
 * @low: The value of the smallest node visited thus far
 * in the recursion tree
 * @high: The value of the largest node visited this far
 * in the recursion tree
 * Return: whether the tree is a valid AVL tree or not
 */
int is_avl(const binary_tree_t *tree, int low, int high)
{
	size_t l_height, r_height, diff;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		l_height = bin_T_height(tree->left);
		r_height = bin_T_height(tree->right);
		diff = l_height > r_height ?
			l_height - r_height : r_height - l_height;
		if (diff > 1)
			return (0);
		return (is_avl(tree->left, low, tree->n - 1) &&
			is_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * is_avl - a function that checks if a tree is an avl tree
 * @tree: A pointer to the root node of the tree
 * Return: whether the tree is a valid AVL tree or not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX));
}
