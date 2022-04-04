#include "binary_trees.h"

/**
 * binary_tree_is_root - sees if a node is the root
 * @node: node to check
 *
 * Return: 1 if leaf otherwise 0
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);
	return (1);
}
