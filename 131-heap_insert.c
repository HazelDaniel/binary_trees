#include "binary_trees.h"


void max_heapify(binary_tree_t *root, binary_tree_t *curr_root);
heap_t *insert_to_max_heap(heap_t **root, heap_t *tree_queue[1000], int value);
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
 * heap_insert - a function that inserts a node into a
 * a binary heap
 * @root: the address of the pointer to the root node
 * @value: the value that the newly added node will
 * hold
 * Return: a pointer to the created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *heap_queue[1000];

	return (insert_to_max_heap(root, heap_queue, value));
}

/**
 * max_heapify - a function that maintains the structural
 * integrity of a binary heap
 * @root: the root node of the binary heap
 * @curr_root: the root node of the current sub-tree
 * Return: void
 **/
void max_heapify(binary_tree_t *root, binary_tree_t *curr_root)
{
	binary_tree_t *largest, *left, *right;
	int tmp;

	if (!curr_root || !root)
		return;
	left = curr_root->left, right = curr_root->right;

	if (left && left->n > curr_root->n)
		largest = left;
	else
		largest = curr_root;
	if (right && right->n > largest->n)
		largest = right;

	if (largest != curr_root)
	{
		tmp = curr_root->n;
		curr_root->n = largest->n;
		largest->n = tmp;
		max_heapify(root, largest);
	}
}
/*
 * NOTES:
 * traverse the tree in a level-order.
 * if you encounter a node that has a left child
 * but not a right child, append new node as its right child
 * else if it's a leaf, attach it to it's left
 * run max heapify on the tree
 * traverse the "tree_queue" in a reverse order
 * run max-heapify on it
 **/

/**
 * insert_to_max_heap - a function that inserts
 * a new node to a max heap
 * @root: the address of the root node of the
 * max heap
 * @tree_queue: the list of nodes collected
 * during a level-order traversal.
 * @value: the value of the node to be inserted
 * Return: the newly inserted node
 **/
heap_t *insert_to_max_heap(heap_t **root, heap_t *tree_queue[1000], int value)
{
	int front = 0, rear = 0, length = 0, i = 0;
	heap_t *current, *new;

	if (!*root)
	{
		new = binary_tree_node(NULL, value);
		*root = new;
		return (new);
	}
	tree_queue[rear++] = *root;
	while (front < rear)
	{
		current = tree_queue[front++];

		if (current->left)
			tree_queue[rear++] = current->left;
		if (current->right)
			tree_queue[rear++] = current->right;
		length++;
	}

	new = binary_tree_node(NULL, value);
	for (i = 0; i < length; i++)
	{
		current = tree_queue[i];
		if (current->left && !current->right)
		{
			current->right = new, new->parent = current;
			break;
		}
		else if (is_leaf(current))
		{
			current->left = new, new->parent = current;
			break;
		}
	}
	for (i = length - 1; i >= 0; i--)
	{
		current = tree_queue[i];
		max_heapify(*root, current);
	}
	return (new);
}
