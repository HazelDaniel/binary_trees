#include "binary_trees.h"


/**
 * binary_tree_rotate_right - a function that rotates
 * the sub-tree of a binary tree to the right
 * @tree: The pointer to the root node of the current
 * sub-tree
 * Return: the new root node of the current sub-tree
 **/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *left_child = tree->left;

	if (!left_child)
		return (tree);
	tree->left = left_child->right;
	if (left_child->right)
		left_child->right->parent = tree;
	left_child->right = tree;
	tree->parent = left_child;

	return (left_child);
}

