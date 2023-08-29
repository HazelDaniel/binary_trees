#include "binary_trees.h"


/**
 * binary_tree_uncle - a function that returns
 * the uncle of a given node in the binary tree
 * @node: the pointer to the given node
 * Return: the uncle
 **/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	if (node->parent->n >= node->parent->parent->n)
		return (node->parent->parent->left);
	else
		return (node->parent->parent->right);
}
