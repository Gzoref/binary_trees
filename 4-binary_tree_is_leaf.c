#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 *
 * @node: Pointer to the node to check
 *
 * Return: 1 if node, otherwise 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

       /* If next node doesn't exist, is leaf, not parent */
	if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}
	return (0);
}
