#include "binary_trees.h"


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
 * tree_height - a function that computes
 * the height of a tree
 * @tree: the pointer to the root node of the tree
 *
 * Return: the height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);
	if (tree->left)
		l_height = 1 + tree_height(tree->left);
	if (tree->right)
		r_height = 1 + tree_height(tree->right);

	return (max(l_height, r_height));
}

/**
 * level_order_print - a function that prints
 * a sub-tree of a binary tree in a BFS order
 * @tree: the pointer to the root node of the current
 * sub-tree
 * @level: the current level in the tree
 * @func: a pointer to the function to call on each visit
 * Return: void
 */
void level_order_print(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		level_order_print(tree->left, level - 1, func);
		level_order_print(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - a function that traverses
 * a binary tree in a BFS manner
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each visit
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0;
	int len = 1;

	if (!tree || !func)
		return;

	height = tree_height(tree) + 1;

	while (len <= height)
		level_order_print(tree, len, func), len++;
}
