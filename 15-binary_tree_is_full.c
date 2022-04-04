#include "binary_trees.h"

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
