#include "binary_trees.h"

/**
 * binary_tree_is_bst - check if binary tree is search tree
 * @tree: pointer to root of tree to check
 *
 * Return: 1 if tree is bst otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int l = -1, r = -1;

	if (!tree || (tree->left && tree->left->n > tree->n)
		|| (tree->right && tree->right->n < tree->n))
		return (0);
	if (tree->left)
		l = binary_tree_is_bst(tree->left);
	if (tree->right)
		r = binary_tree_is_bst(tree->right);
	if (l == 0 || r == 0)
		return (0);
	if (l == 1 && tree->left->right && tree->left->right->n > tree->n)
		return (0);
	if (r == 1 && tree->right->left && tree->right->left->n <  tree->n)
		return (0);
	return (1);
}
