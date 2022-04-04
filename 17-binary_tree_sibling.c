#include "binary_trees.h"

/**
 * binary_tree_sibling - finds a node's sibling
 * @node: node to search
 *
 * Return: pointer to sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *p;

	if (node == NULL || !node->parent)
		return (NULL);
	p = node->parent;
	if (p->left == node)
		return (p->right);
	return (p->left);
}
