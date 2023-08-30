#ifndef ___BINARY_TREES_
#define ___BINARY_TREES_

#include "stdlib.h"
#include "stddef.h"
#include <stdio.h>

#define STRUCTTAG struct

/* STRUCTURES */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

/**
 * struct b_tree_list - a linked list
 * containing pointer to nodes in a
 * binary trees due to some pre-computations
 *
 * @value: the pointer to the current
 * node in the list
 * @next: the pointer to the next
 * item in the linked list
 * @prev: the pointer to the previous item in the
 * linked list
 **/
STRUCTTAG b_tree_list
{
	struct binary_tree_s *value;//DON'T FREE
	struct b_tree_list *next;
};

/* TYPEDEFS */
typedef STRUCTTAG binary_tree_s binary_tree_t;
typedef STRUCTTAG binary_tree_s bst_t;
typedef STRUCTTAG binary_tree_s avl_t;
typedef STRUCTTAG binary_tree_s heap_t;
typedef STRUCTTAG b_tree_list b_tree_list_t;

/* UTILITY FUNCTIONS */
void binary_tree_print(const binary_tree_t *tree);
b_tree_list_t *create_b_tree_list(binary_tree_t * value);
void append_b_tree_list(b_tree_list_t **head_ptr, binary_tree_t *node);
void prepend_b_tree_list(b_tree_list_t **head_ptr, binary_tree_t *node);
void free_b_tree_list(b_tree_list_t **head_ptr);

/* CORE FUNCTIONS */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);
#endif/*___BINARY_TREES_*/
