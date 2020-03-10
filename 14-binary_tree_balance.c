#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree to traverse
 *
 * Return: If tree is NULL, return 0, else balance
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t _left, _right;
	int balance;

	if (tree == NULL)
	{
		return (0);
	}
	_left = binary_tree_height(tree->left);
	_right = binary_tree_height(tree->right);

	if (tree->left != NULL)
	{
		_left++;
	}

	if (tree->right != NULL)
	{
		_left++;
	}

	balance = _left - _right;

	return (balance);
}



/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the tree, returns 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t _left, _right;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}

	_left = binary_tree_height(tree->left);
	_right = binary_tree_height(tree->right);
	if (_left >= _right)
		return (_right + 1);
	return (_left + 1);
}
