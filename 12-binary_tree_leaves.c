#include "binary_trees.h"
#include "4-binary_tree_is_leaf.c"


/**
 * binary_tree_leaves - a function that returns
 * |V| where V is the vertex set of vertices/nodes
 * with each vertex/node having
 * just one neighbor(its parent) and no outgoing edges
 * @tree: the pointer to the root node
 * Return: the number of leaves
 **/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t total_leaves = 0;

	if (!tree)
		return (0);
	if (binary_tree_is_leaf(tree)) {
		return (1);
	}
	total_leaves += binary_tree_leaves(tree->left);
	total_leaves += binary_tree_leaves(tree->right);

	return (total_leaves);
}
