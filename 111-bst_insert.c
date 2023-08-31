#include "binary_trees.h"


/**
 * insert_recurse - a function that recursively traverses
 * a Binary Search Tree to insert a new value
 * @tree: the pointer to the root node
 * @value: the value of the node to insert
 * Return: the node inserted
 */
bst_t *insert_recurse(bst_t *tree, int value)
{
	bst_t *new = NULL;

	if (tree->n > value)
	{
		if (tree->left == NULL)
		{
			new = binary_tree_node(tree, value);
			tree->left = new;
			return (new);
		}
		return (insert_recurse(tree->left, value));
	}

	if (tree->n < value)
	{
		if (tree->right == NULL)
		{
			new = binary_tree_node(tree, value);
			tree->right = new;
			return (new);
		}
		return (insert_recurse(tree->right, value));
	}

	return (NULL);
}


/**
 * bst_insert - a function that inserts a value
 * in a BST
 * @tree: the address of the root node
 * @value: the value of the new node
 * Return: pointer to new node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new = NULL;

	if (!tree || !(*tree))
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}

	return (insert_recurse(*tree, value));
}
