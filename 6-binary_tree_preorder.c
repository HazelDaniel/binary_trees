#include "binary_trees.h"


/**
 * binary_tree_preorder - a function that
 * walks a tree in a pre-order manner
 * and calls a function at every point of the traversal
 * @tree: the pointer to the root node of a binary tree
 * @func: a function to be called
 * Return: void
 **/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
