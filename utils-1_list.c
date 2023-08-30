#include "binary_trees.h"

/**
 * create_b_tree_list - a function that creates
 * a linked list of binary tree nodes
 * @value: the value of the head node
 * Return: the head node
 **/
b_tree_list_t *create_b_tree_list(binary_tree_t *value)
{
	b_tree_list_t *head = NULL;

	head = (b_tree_list_t *)malloc(sizeof(b_tree_list_t));
	if (!head)
		return (head);
	head->value = value;
	head->next = NULL;

	return (head);
}


/**
 * append_b_tree_list - a function that
 * appends a binary tree node to a linked list
 * @node: the binary tree node to append
 * Return: void
 **/
void append_b_tree_list(b_tree_list_t **head_ptr, binary_tree_t *node)
{
	b_tree_list_t *curr = *head_ptr, *new;

	new = (b_tree_list_t *)malloc(sizeof(b_tree_list_t));
	if (!new)
		return;

	new->value = node;
	new->next = NULL;

	if (!curr)
		*head_ptr = new;

	while (curr && curr->next)
		curr = curr->next;

	curr->next = new;
}

/**
 * prepend_b_tree_list - a function that
 * prepends a binary tree node to a linked list
 * @node: the binary tree node to prepend
 * Return: void
 **/
void prepend_b_tree_list(b_tree_list_t **head_ptr, binary_tree_t *node)
{
	b_tree_list_t *new;

	new = (b_tree_list_t *)malloc(sizeof(b_tree_list_t));
	if (!new)
		return;


	new->value = node;
	new->next = *head_ptr;
	*head_ptr = new;
}


/**
 * free_b_tree_list - a function that frees up resources
 * used when creating a binary tree list
 * @head_ptr: the address of the head pointer of the list
 * Return: void
 **/
void free_b_tree_list(b_tree_list_t **head_ptr)
{
	b_tree_list_t *curr = *head_ptr, *tmp;

	if (!curr)
		return;

	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}

	*head_ptr = NULL;
}
