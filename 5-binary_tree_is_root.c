#include "binary_trees.h"


/**
 * binary_tree_is_root - a function that returns
 * whether a node is the root of a binary tree
 * @node: the node to check against
 * Return: boolean
 **/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return (!(node->parent));
}
