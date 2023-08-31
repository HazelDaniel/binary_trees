#include "binary_trees.h"

avl_t *avl_search(avl_t *tree, int value);
/**
 * avl_remove - function that removes a node from
 * an AVL tree
 * @root: the root node of the current sub-tree
 * @value: the value of the node to remove
 * Return: the new root of the AVL tree if successful
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *d_node, *successor;

	d_node = avl_search(root, value);
	if (!d_node)
		return (NULL);
	if (d_node->left && d_node->right)
	{
		for (successor = d_node->right; successor && successor->left;)
			successor = successor->left;
		d_node->n = successor->n, d_node = successor;
	}
	if (d_node->left)
	{
		d_node->left->parent = d_node->parent;
		if (d_node == d_node->parent->right)
			d_node->parent->right = d_node->left;
		else
			d_node->parent->left = d_node->left;
	}
	else if (d_node->right)
	{
		d_node->right->parent = d_node->parent;
		if (d_node == d_node->parent->right)
			d_node->parent->right = d_node->right;
		else
			d_node->parent->left = d_node->right;
	}
	else
	{
		if (d_node == d_node->parent->right)
			d_node->parent->right = NULL;
		else
			d_node->parent->left = NULL;
		d_node->parent = NULL;
	}
	free(d_node);
	return (root);
}

/**
 * avl_search - a function that searches for a value in
 * an AVL tree
 * @tree: the root node of the current sub-tree
 * @value: the value of the node to search
 * Return: the node that matches the value
 */
avl_t *avl_search(avl_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value == tree->n)
		return (tree);
	if (value < tree->n)
		return (avl_search(tree->left, value));
	if (value > tree->n)
		return (avl_search(tree->right, value));
	return (NULL);
}
