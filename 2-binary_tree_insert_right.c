#include "binary_trees.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * binary_tree_insert_right - inserts a node to the right of parent
 * @parent: parent node to insert child under
 * @value: value to create new node data
 *
 * Return: pointer to new binary tree node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)/*Steph*/
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = parent->right;

	if (parent->right != NULL)
		parent->right->parent = new;

	parent->right = new;

	return (new);
}
