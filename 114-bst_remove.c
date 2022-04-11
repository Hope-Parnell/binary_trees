#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

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

	/* No children or right-child only */
	if (!hide->left)
	{
		if (parent && parent->left == hide)
			parent->left = hide->right;
		else if (parent)
			parent->right = hide->right;
		if (hide->right)
			hide->right->parent = parent;
		free(hide);
		return (parent == NULL ? hide->right : root);
	}

	/* Left-child only */
	if (!hide->right)
	{
		if (parent && parent->left == hide)
			parent->left = hide->left;
		else if (parent)
			parent->right = hide->left;
		if (hide->left)
			hide->left->parent = parent;
		free(hide);
		return (parent == NULL ? hide->left : root);
	}

	/* Two children */
	successor = inorder_successor(hide->right);
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
	if (seek != NULL)
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
