#include "binary_trees.h"
#include "utils-1_list.c"


/**
 * binary_trees_ancestor - a function that returns
 * the lowest common ancestor of two distinct nodes
 * in a binary tree
 * @first: the first node
 * @second: the second node
 * Return: the LCA
 **/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	b_tree_list_t *first_ancestors = NULL, *second_ancestors = NULL;
	binary_tree_t *lca = NULL;
	void *curr, *curr2, *last, *last2;
	int depth = -1, depth2 = -1;

	if (!first || !second)
		return (NULL);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	if (second->parent == first)
		return ((binary_tree_t *)first);
	curr = (binary_tree_t *)first, last = curr;
	while (curr)
	{
		prepend_b_tree_list(&first_ancestors, curr);
		curr = ((binary_tree_t *)curr)->parent, depth++;
	}
	curr2 = (binary_tree_t *)second, last2 = curr2;
	while (curr2)
	{
		prepend_b_tree_list(&second_ancestors, curr2);
		curr2 = ((binary_tree_t *)curr2)->parent, depth2++;
	}
	curr = first_ancestors, curr2 = second_ancestors;
	if (first_ancestors->value != second_ancestors->value)
		return (NULL);
	while (depth < depth2)
		last2 = ((binary_tree_t *)last2)->parent, depth++;
	while (depth2 < depth)
		last = ((binary_tree_t *)last)->parent, depth2++;
	for (; ((b_tree_list_t *)curr)->value != last &&
	((b_tree_list_t *)curr2)->value != last2;)
	{
		if (((b_tree_list_t *)curr)->value->n ==
			(((b_tree_list_t *)curr2)->value->n))
			lca = (((b_tree_list_t *)curr)->value);
		curr = ((b_tree_list_t *)curr)->next, curr2 = ((b_tree_list_t *)curr2)->next;
	}

	return (lca);
}
