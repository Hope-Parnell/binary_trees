#include "binary_trees.h"

/**
 * bst_insert - inserts a node in a binary search tree
 * @tree: double pointer to root node
 * @value: value to insert
 *
 * Return: newly created node, NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent, *new;

	if (tree)
	{
		parent = *tree;

		if (!parent)
		{
			new = binary_tree_node(parent, value);
			if (!new)
				return (NULL);
			return (*tree = new);
		}

		if (value < parent->n) /* insert in left subtree */
		{
			if (parent->left)
				return (bst_insert(&parent->left, value));
			new = binary_tree_node(parent, value);
			if (!new)
				return (NULL);
			return (parent->left = new);
		}
		if (value > parent->n) /* insert in right subtree */
		{
			if (parent->right)
				return (bst_insert(&parent->right, value));

			new = binary_tree_node(parent, value);
			if (!new)
				return (NULL);
			return (parent->right = new);
		}
	}
	return (NULL);
}
