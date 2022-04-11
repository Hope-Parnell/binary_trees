#include "binary_trees.h"

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @hide: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *hide)
{
	bst_t *parent = hide->parent, *successor = NULL;

	if (!hide->left)
	{
		if (parent && parent->left == hide)
			parent->left = hide->right;
		else if (parent)
			parent->right = hide->right;
		if (hide->right)
			hide->right->parent = parent;
		free(hide);
		return (!parent ? hide->right : root);
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
		return (!parent ? hide->left : root);
	}
	for (successor = hide->right; successor->left; successor = successor->left)
		hide->n = successor->n;
	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @seek: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *seek, int value)
{
	if (seek)
	{
		if (seek->n == value)
			return (bst_delete(root, seek));
		if (seek->n > value)
			return (bst_remove_recursive(root, seek->left, value));
		return (bst_remove_recursive(root, seek->right, value));
	}
	return (NULL);
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
	return (bst_remove_recursive(root, root, value));
}
