#include "binary_trees.h"
/**
 *
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *hide, *seek, *child = NULL;

	seek = bst_search(root, value);
	if (!seek)
		return (root);
	if (seek->left && seek->right)
	{
		for (hide = seek->right; hide->left; hide = hide->left)
		;
		seek->n = hide->n;
		hide->parent->left = NULL;
		free(hide);
		return (root);
	}
	else
	{
		if (seek->right)
			child = seek->right;
		if (seek->left)
			child = seek->left;
		if (seek == root)
			root = child;
		else if (seek->parent->left == seek)
			seek->parent->left = child;
		else
			seek->parent->right = child;
		free(seek);
		return (root);
	}
	return (root);
}

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
