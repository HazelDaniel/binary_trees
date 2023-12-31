#include "binary_trees.h"


/**
 * binary_tree_is_leaf - a function that returns whether
 * a node is a leaf
 * @node: the node to check against
 * Return: boolean
 **/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return ((!(node->left || node->right)));
}
