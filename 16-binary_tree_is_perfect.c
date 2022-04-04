#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if tree is perfect
 * @tree: tree to check
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (binary_tree_balance(tree) != 0 || binary_tree_is_full(tree) == 0)
		return (0);
	return (1);
}

/**
 * height - returns the height of a binary tree
 * @tree: pointer to root
 *
 * Return: height of the tree including root
 */

size_t height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	left = 1 + height(tree->left);
	right = 1 + height(tree->right);
	return (left > right ? left : right);
}

/**
 * binary_tree_balance - checks balace factor
 * @tree: root of tree
 *
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (height(tree->left) - height(tree->right));
}
/**
 * binary_tree_is_full - checks if tree is full
 * @tree: root of tree
 *
 * Return: 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int l, r;

	if (!tree || (tree->left && !tree->right) || (!tree->left && tree->right))
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	l = binary_tree_is_full(tree->left);
	r = binary_tree_is_full(tree->right);
	if (l != r)
		return (0);
	return (1);
}
