#include "binary_trees.h"


/**
 * binary_tree_node - a function that creates a binary
 * tree node and attaches it to its parent
 * @parent: the parent of the new node to be created
 * @value: the value that tne new node will hold
 * Return: binary_tree_t *
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->n = value;
	new_node->parent = parent;
	if (!parent)
		return (new_node);
	if (value > parent->n)
		parent->right = new_node;
	else
		parent->left = new_node;

	return (new_node);
}
