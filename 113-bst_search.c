#include "binary_trees.h"

/**
 * bst_search - search for a value in a bst
 * @tree: root of tree to search
 * @value: value to check for
 *
 * Return: pointer to node where value was found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);
	if (tree->n > value)
		return (bst_search(tree->left, value));
	if (tree->n < value)
		return (bst_search(tree->right, value));
	return (NULL);
}
