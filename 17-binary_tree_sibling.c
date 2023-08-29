#include "binary_trees.h"


/**
 * binary_tree_sibling - a function that returns
 * the sibling of a given node in the binary tree
 * @node: the pointer to the given node
 * Return: the sibling
 **/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->n >= node->parent->n)
		return (node->parent->left);
	else
		return (node->parent->right);
}
