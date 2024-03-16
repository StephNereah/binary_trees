#include "binary_trees.h"

/**
 * binary_trees_leaves - gets the # of leaves of a binary tree
 * @tree: root node to draw height from tree
 *
 * Return: size_t representing height, 0/ NULL on failure
 */
size_t binary_tree_leaves(const binary_tree_t *tree)/*Steph*/
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
