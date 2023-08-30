#ifndef ___B_TREE_LIST_
#define ___B_TREE_LIST_
#include "binary_trees.h"

/* TYPEDEFS */
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;
typedef struct b_tree_list b_tree_list_t;
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
struct b_tree_list
{
	struct binary_tree_s *value;//DON'T FREE
	struct b_tree_list *next;
};

b_tree_list_t *create_b_tree_list(binary_tree_t * value);
void append_b_tree_list(b_tree_list_t **head_ptr, binary_tree_t *node);
void prepend_b_tree_list(b_tree_list_t **head_ptr, binary_tree_t *node);
void free_b_tree_list(b_tree_list_t **head_ptr);
#endif/*___B_TREE_LIST_*/
