#include "binary_trees.h"

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *hide)
{
	bst_t *parent = hide->parent, *seek = NULL;

	if (!hide)
		return (root);
	if (!hide->left)
	{
		if (parent && parent->left == hide)
			parent->left = hide->right;
		else if (parent)
			parent->right = hide->right;
		if (hide->right)
			hide->right->parent = parent;
		free(hide);
		return (parent ? root : hide->right);
	}
	if (!hide->right)
	{
		if (parent && parent->left == hide)
			parent->left = hide->left;
		else if (parent)
			parent->right = hide->left;
		if (hide->left)
			hide->left->parent = parent;
		free(hide);
		return (parent ? root : hide->left);
	}
	for (seek = hide->right; seek->left; seek = seek->left)
		hide->n = seek->n;
	return (bst_delete(root, seek));
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_delete(root, bst_search(root, value)));
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
