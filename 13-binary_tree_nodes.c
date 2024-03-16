#include "binary_trees.h"

/**
 * binary_tree_nodes - gets the # of nodes of a binary tree
 * @tree: root node
 *
 * Return: size rep height, 0 on failure/ NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);
	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);
	nodes += (tree->right || tree->left) ? 1 : 0;
	return (nodes);
}
