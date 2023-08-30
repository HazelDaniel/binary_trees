#include "binary_trees.h"

int bin_tree_depth(const binary_tree_t *tree);


/**
 * binary_trees_ancestor - a function that finds the lowest
 * common ancestor of two nodes in a binary tree
 * @first: the first node
 * @second: the second node
 * Return: LCA
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t depth1, depth2;
	binary_tree_t *tmp1, *tmp2;

	depth1 = bin_tree_depth(first);
	depth2 = bin_tree_depth(second);

	if (depth1 == 0 || depth2 == 0)
		return (NULL);

	tmp1 = (binary_tree_t *)first;
	tmp2 = (binary_tree_t *)second;
	if (depth1 > depth2)
	{
		while (depth1 != depth2)
			tmp1 = tmp1->parent, depth1--;
	}
	else if (depth1 < depth2)
	{
		while (depth1 != depth2)
			tmp2 = tmp2->parent, depth2--;
	}

	while (tmp1 != tmp2)
		tmp1 = tmp1->parent, tmp2 = tmp2->parent;


	return (tmp1);
}
#include "b_tree_list.hpp"

/**
 * bin_tree_depth - a function that returns the depth
 * of a node in a binary tree
 * @node: the given node
 * Return: the depth
 */
int bin_tree_depth(const binary_tree_t *node)
{
	if (node && node->parent)
		return (1 + bin_tree_depth(node->parent));

	return (0);
}
