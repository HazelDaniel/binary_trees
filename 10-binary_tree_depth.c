#include "binary_trees.h"


/**
 * binary_tree_depth - a function that returns the number of edges
 * in the path from the root to a given node
 * @tree: the pointer to the root node
 * Return: the depth |E|.
 * E = the edge set on the path v0,..., vk where:
 * 		v0 = the root node
 * 		vk = the target node
 **/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *curr_parent = NULL;

	if (!tree)
		return (0);
	curr_parent = tree->parent;
	while (curr_parent)
	{
		depth++;
		curr_parent = curr_parent->parent;
	}
	return (depth);
}
