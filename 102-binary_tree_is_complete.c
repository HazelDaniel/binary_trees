#include "binary_trees.h"
#include "10-binary_tree_depth.c"

static int level_order_queue(binary_tree_t
	 *tree_queue[1000], binary_tree_t *tree);

/**
 * is_leaf - a function that returns whether
 * a node is a leaf
 * @node: the node to check against
 * Return: boolean
 **/
int is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return ((!(node->left || node->right)));
}

/**
 * binary_tree_is_complete - a function that checks if a binary tree
 * is complete
 * @tree: the pointer to the root node of the binary tree
 * Return: whether it is complete or not
 * Description: these are the steps to follow in order to check
 *              for completeness of a binary tree:
 *              1. traverse the tree in a level-order manner
 *              2. if a node has a NULL left-child.
 *               a. it must have a null right-child.
 *               b. all other nodes following it must have no children
 *              2. if a node has a non-NULL left-child but a null right child
 *               a. all other nodes following it must have no children
 *              else:
 *                we have violated the property and we return false
 *
 **/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *tree_queue[1000], *current;
	int i = 0, j = 0, length = 0, l_child_depth = 0;

	if (!tree)
		return (0);
	length = level_order_queue(tree_queue, (binary_tree_t *)tree);
	for (i = 0; i < length; i++)
	{
		current = tree_queue[i];
		if (is_leaf(current))
			continue;
		if (!current->left)
		{
			if (current->right)
				return (0);
			j = i + 1, current = tree_queue[j];
			while (j < length &&
					binary_tree_depth(current) == binary_tree_depth(tree_queue[i]))
			{
				current = tree_queue[j++];
				if (!is_leaf(current))
					return (0);
			}
		}
		else
		{
			if (!current->right)
			{
				l_child_depth = binary_tree_depth(current->left),
					j = i + 1, current = tree_queue[j];
				while (j < length)
				{
					current = tree_queue[j++];
					if (binary_tree_depth(current) > (size_t)l_child_depth)
						return (0);
				}
				j = i + 1, current = tree_queue[j];
				while (j < length &&
					binary_tree_depth(current) == binary_tree_depth(tree_queue[i]))
				{
					current = tree_queue[j++];
					if (!is_leaf(current))
						return (0);
				}
			}
		}
	}
	return (1);
}

/**
 * level_order_queue - a function that returns
 * an array implementation of a queue
 * of all the nodes visited during a level order
 * @tree_queue: the array of size 1000
 * @tree: the pointer to the root node
 * Return: the length of the queue
 *
 **/
static int level_order_queue(binary_tree_t
	*tree_queue[1000], binary_tree_t *tree)
{
	int front = 0, rear = 0, length = 0;
	binary_tree_t *current;

	tree_queue[rear++] = tree;
	while (front < rear)
	{
		current = tree_queue[front++];

		if (current->left)
			tree_queue[rear++] = current->left;

		if (current->right)
			tree_queue[rear++] = current->right;
		length++;
	}
	return (length);
}
