#include "binary_trees.h"
#include <stdio.h>

int binary_tree_not_full(const binary_tree_t *tree);

/**
 * binary_tree_is_full - checks if the binary tree is full or not
 * @tree: tree root
 *
 * Return: (1) if full (0) if otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int non_full_nodes = 0;

	if (!tree)
		return (0);
	non_full_nodes = binary_tree_not_full(tree);
	return ((non_full_nodes) ? 0 : 1);
}

/**
 * binary_tree_not_full - recursive helper function
 * @tree: tree root
 *
 * Return: number of non full nodes found
 */
int binary_tree_not_full(const binary_tree_t *tree)
{
	size_t non_full_nodes = 0;

	if (!tree)
		return (0);

	if ((tree->right && !tree->left) || (tree->left && !tree->right))
		return (1);
	non_full_nodes += binary_tree_not_full(tree->left);
	non_full_nodes += binary_tree_not_full(tree->right);
	return (non_full_nodes);
}
