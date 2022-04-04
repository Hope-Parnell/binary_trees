#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: the parent node
 * @value: value to store in the new node
 *
 * Return: the newly created node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent && parent->left && parent->right) /*parent is full*/
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = NULL;
	if (!parent)
	{
		new->parent = NULL; }
	else
	{
		new->parent = parent;
		if (!parent->left)
			parent->left = new;
		else /*left child already exists*/
			parent->right = new;
	}
	return (new);
}
