#include "binary_trees.h"
#include "14-binary_tree_balance.c"
#include <stdio.h>


/**
 * binary_tree_is_full - a function that returns
 * whether a binary tree is full or not
 * @tree: the pointer to the root node of the binary
 * tree
 * description: two main logics you could use are
 *             1. check if all internal nodes in the
 *             tree have two children
 *             2. check if the sum of the balance factors
 *             of all nodes in the tree equals 0.
 *             let's go with 2 shall we.
 * Return: void
 **/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int balance_total = 0;

	if (!tree)
		return (0);
	balance_total += binary_tree_balance(tree->left);
	balance_total += binary_tree_balance(tree->right);
	balance_total += (binary_tree_balance(tree));

	return (balance_total == 0);
}
