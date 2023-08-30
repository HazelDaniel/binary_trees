#include "binary_trees.h"


/**
 * binary_tree_rotate_left - a function that rotates
 * the sub-tree of a binary tree to the left
 * @tree: The pointer to the root node of the current
 * sub-tree
 * Return: the new root node of the current sub-tree
 **/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right_child = tree->right;

	if (!right_child)
		return (NULL);
	tree->right = right_child->left;
	if (right_child->left)
		right_child->left->parent = tree;
	right_child->left = tree;
	tree->parent = right_child;

	return (right_child);
}
