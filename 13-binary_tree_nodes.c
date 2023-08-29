#include "binary_trees.h"
#include <stdio.h>


/**
 * is_internal_node - a function that returns
 * whether a node is an internal node.
 * an internal node is a node that has at least one
 * child node
 * @node: the node to check against
 * Return: boolean
 **/
int is_internal_node(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return ((node->left || node->right));
}

/**
 * binary_tree_nodes - a function that returns
 * |V| where V is the vertex set of vertices/nodes
 * with each vertex/node being an internal node
 * @tree: the pointer to the root node
 * Return: the number of leaves
 **/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t total_leaves = 0;

	if (!tree)
		return (0);
	if (is_internal_node(tree))
	{
		total_leaves = 1;
	}
	total_leaves += binary_tree_nodes(tree->left);
	total_leaves += binary_tree_nodes(tree->right);

	return (total_leaves);
}
