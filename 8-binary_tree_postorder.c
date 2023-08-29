#include "binary_trees.h"


/**
 * binary_tree_postorder - a function that
 * walks a tree in an post-order manner
 * and calls a function at every point of the traversal
 * @tree: the pointer to the root node of a binary tree
 * @func: a function to be called
 * Return: void
 **/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
