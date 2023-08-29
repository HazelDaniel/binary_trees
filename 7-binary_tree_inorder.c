#include "binary_trees.h"


/**
 * binary_tree_inorder - a function that
 * walks a tree in an in-order manner
 * and calls a function at every point of the traversal
 * @tree: the pointer to the root node of a binary tree
 * @func: a function to be called
 * Return: void
 **/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
