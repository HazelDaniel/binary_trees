#include "binary_trees.h"

int bin_tree_depth(const binary_tree_t *tree);

b_tree_list_t *create_b_tree_list(binary_tree_t * value);
void append_b_tree_list(b_tree_list_t **head_ptr, binary_tree_t *node);
void prepend_b_tree_list(b_tree_list_t **head_ptr, binary_tree_t *node);
void free_b_tree_list(b_tree_list_t **head_ptr);

/**
 * struct b_tree_list - a linked list
 * containing pointer to nodes in a
 * binary trees due to some pre-computations
 *
 * @value: the pointer to the current
 * node in the list
 * @next: the pointer to the next
 * item in the linked list
 * @prev: the pointer to the previous item in the
 * linked list
 **/
struct b_tree_list
{
	struct binary_tree_s *value;//DON'T FREE
	struct b_tree_list *next;
};

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
