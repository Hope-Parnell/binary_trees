#include "binary_trees.h"

/**
 * binary_tree_uncle - find a node's pibling
 * @node: nibling node
 *
 * Return: node's pibling
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
