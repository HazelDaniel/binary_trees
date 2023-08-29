#include "binary_trees.h"

/**
 * binary_tree_insert_right - a function that inserts
 * a node to the right of an internal node
 * @parent: the internal node that is bouta be a parent
 * @value: the value that the newly created node is bouta
 * have
 * Return: binary_tree_t
 **/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (new_node)
	{
		new_node->n = value;
		new_node->parent = parent;
		new_node->right = NULL;
		new_node->left = NULL;
	}
	else
	{
		return (NULL);
	}
	if (!parent)
	{
		free(new_node);
		return (NULL);
	}
	if (parent->right)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;
	return (new_node);
}
