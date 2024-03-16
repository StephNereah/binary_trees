#include "binary_trees.h"

int binary_tree_not_full(const binary_tree_t *tree);
size_t binary_tree_h(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: root node
 *
 * Return: (1) if tree is perfect, (0) otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	char is_balanced = (binary_tree_balance(tree) == 0) ? 1 : 0;
	int is_full = binary_tree_is_full(tree);

	if (!tree)
		return (0);
	return (is_balanced && is_full);
}

/**
 * binary_tree_is_full - checks if a binary tree is full or not
 * @tree: root node
 *
 * Return: (1) if binary tree is full (0) on anything else
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
 * @tree: root node
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

/**
 * binary_tree_balance - calculate balance factor for tree
 * @tree: root node
 *
 * Return: balance factor of tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (!tree)
		return (0);

	height_l = binary_tree_h(tree->left);
	height_r = binary_tree_h(tree->right);
	return (height_l - height_r);
}

/**
 * binary_tree_h - gets height of binary tree - copied
 * @tree: root node
 *
 * Return: height of tree
 */
size_t binary_tree_h(const binary_tree_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;

	if (!tree)
		return (0);
	l_height += (tree) ? 1 + binary_tree_h(tree->left) : 0;
	r_height += (tree) ? 1 + binary_tree_h(tree->right) : 0;
	return ((r_height > l_height) ? r_height : l_height);
}
