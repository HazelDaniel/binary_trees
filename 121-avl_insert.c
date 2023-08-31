#include "binary_trees.h"
#include <limits.h>
#include <math.h>


/**
 * balance_avl - balance the AVL tree
 * @tree: AVL tree
 * @value: value of the node to insert
 */
void balance_avl(avl_t **tree, int value)
{
	int isBalanced;

	isBalanced = binary_tree_balance(*tree);
	if (isBalanced > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);

	else if (isBalanced > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (isBalanced < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (isBalanced < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
}

/**
 * recurse_insert - a function that inserts a node
 * into an AVL tree
 * @tree: the pointer to the root node of the AVL sub-tree
 * @parent: the pointer to the parent of the root node
 * in a sub-tree
 * @node: the address of the new node
 * @value: the value of the node to be inserted
 * Return: the new root of the AVL tree if success
 */
avl_t *recurse_insert(avl_t **tree, avl_t *parent, avl_t **node, int value)
{
	if (*tree == NULL)
	{
		*node = binary_tree_node(parent, value);
		return (*node);
	}
	if ((*tree)->n > value)
	{
		(*tree)->left = recurse_insert(&(*tree)->left, *tree, node, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = recurse_insert(&(*tree)->right, *tree, node, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	balance_avl(tree, value);
	return (*tree);
}

/**
 * avl_insert - insert a new node in an AVL
 * @tree: tree
 * @value: value of the new node
 * Return: node (success) | NULL (failed)
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	bst_t *node = NULL;

	if ((*tree) == NULL)
	{
		(*tree) = binary_tree_node(*tree, value);
		return (*tree);
	}

	recurse_insert(tree, *tree, &node, value);
	return (node);
}
