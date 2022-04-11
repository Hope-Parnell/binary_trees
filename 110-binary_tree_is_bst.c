#include "binary_trees.h"
#include <limits.h>

/**
 * bstHelper - helps determine if a binary tree is a bst
 * @node: node to check
 * @min: min value for node
 * @max: max value for node
 *
 * Return: 1 if meets requiremnets otherwise 0
 */

int bstHelper(const binary_tree_t *node, int min, int max)
{
	if (!node)
		return (1);
	if (node->n < min || node->n > max)
		return (0);
	return (bstHelper(node->left, min, node->n - 1)
			&& bstHelper(node->right, node->n + 1, max));
}


/**
 * binary_tree_is_bst - check if binary tree is search tree
 * @tree: pointer to root of tree to check
 *
 * Return: 1 if tree is bst otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return(bstHelper(tree, INT_MIN, INT_MAX));
}
