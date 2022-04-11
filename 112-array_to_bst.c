#include "binary_trees.h"
/**
 * array_to_bst - creates a BST from an array
 * @array: pointer to array to be used
 * @size: length of the array
 *
 * Return: newly made BST, NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *tree = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&tree, array[i]);
	return (tree);
}
