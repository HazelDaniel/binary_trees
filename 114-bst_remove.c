#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * bst_find_min - a function that finds the minimum node
 * in the sub-tree of a BST
 * @tree: the root of a sub-tree
 * Return: the node containing the minimum value
 */
static bst_t *bst_find_min(bst_t *tree)
{
	bst_t *temp = NULL;

	temp = tree;
	while (temp && temp->left)
		temp = temp->left;

	return (temp);
}


/**
 * bst_remove - a function that removes a node from the BST
 * and replaces it by its in-order successor
 * @root: the pointer to the root node
 * @value: the value of the node to remove
 * Return: the new root node of the sub-tree after the removal
 * has been done
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
		if (root->left)
			root->left->parent = root;
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
		if (root->right)
			root->right->parent = root;
	}
	else
	{
		if (root->left == NULL)
		{
			temp = root->right, free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left, free(root);
			return (temp);
		}
		temp = bst_find_min(root->right), root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
		if (root->right)
			root->right->parent = root;
	}
	return (root);
}
