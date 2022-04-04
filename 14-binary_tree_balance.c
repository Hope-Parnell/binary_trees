#include "binary_trees.h"

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
