#include "binary_trees.h"



size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t ct;
	binary_tree_t *p;

	if (!tree)
		return (0);
	for (ct = 0, p = tree->parent; p; ct++, p = p->parent)
	;
	return (ct);
}
