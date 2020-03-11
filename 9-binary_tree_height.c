#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the tree, returns 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t _left, _right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	_left = binary_tree_height(tree->left) + 1;
	_right = binary_tree_height(tree->right) + 1;

	if (_left > _right)
		return (_left);
	return (_right );
}
