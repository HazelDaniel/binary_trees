#include "binary_trees.h"


/**
 * binary_tree_size - a function that returns
 * |V| where V is the vertex set on graph G
 * and G is the binary tree
 * @tree: the pointer to the root node
 * Return: size_t
 **/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t l_size, r_size;

	if (!tree)
		return (0);

	l_size = binary_tree_size(tree->left);
	r_size = binary_tree_size(tree->right);
	return (l_size + r_size + 1);
}
