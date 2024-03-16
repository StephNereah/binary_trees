#include "binary_trees.h"

/**
 * binary_tree_leaves - gets the # of the leaves of a binary tree
 * @tree: tree root
 *
 * Return: size_t represensting height, 0 on failure?/ NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	leaves += binary_tree_leaves(tree->left);
	leaves += binary_tree_leaves(tree->right);
	return (leaves);
}
