#include "binary_trees.h"
#include <stdlib.h>


/**
 * max - a function that returns the maximum between two
 * unsigned integers
 * @a: operand a
 * @b: operand b
 * Return: maximum
 **/
size_t max(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	return (b);
}

/**
 * bin_T_height - a procedure to generate the
 * height of the binary tree for the main function
 * @tree: the pointer to the root node of the binary Tree
 * Return: height
 **/
static size_t bin_T_height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	l_height = bin_T_height(tree->left);
	r_height = bin_T_height(tree->right);

	return ((max(l_height, r_height)) + 1);
}

/**
 * tree_size_h - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size_h(tree->left);

	if (tree->right)
		height_r = 1 + tree_size_h(tree->right);

	return (height_l + height_r);
}

/**
 * _preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traverse
 * @height: height of tree
 *
 * Return: No Return
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - a function that preserves the
 * structural integrity of a binary heap
 * @root: the pointer to the root node of
 * the binary heap
 * Return: void
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!root)
		return;

	tmp1 = root;

	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		value = tmp1->n, tmp1->n = tmp2->n;
		tmp2->n = value, tmp1 = tmp2;
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	_preorder(heap_r, &node, bin_T_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r), *root = heap_r;
	return (value);
}
