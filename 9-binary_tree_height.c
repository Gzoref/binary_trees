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

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the tree, returns 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t _left, _right;

	if (tree == NULL || binary_tree_is_leaf(tree))
	{
		return (0);
	}

	_left = binary_tree_height(tree->left);
	_right = binary_tree_height(tree->right);

	if (_left > _right)
	{
		return (_left + 1);
	}
	else
	{
		return (_right + 1);
	}
}
