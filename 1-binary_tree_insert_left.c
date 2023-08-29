#include "binary_trees.h"


/**
 * binary_tree_insert_left - a function that inserts
 * a node to the left of an internal node
 * @parent: the internal node that is bouta be a parent
 * @value: the value that the newly created node is bouta
 * have
 * Return: binary_tree_t
 **/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (new_node)
	{
		new_node->n = value;
		new_node->parent = parent;
	}
	else
	{
		return (new_node);
	}
	if (!parent)
	{
		free(new_node);
		return (parent);
	}
	if (parent->left && new_node)
	{
		parent->left->parent = new_node;
		new_node->left = parent->left;
	}
	parent->left = new_node;
	return (new_node);
}
