#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverse binary tree using pre-order
 *
 * @tree: Pointer to the root node of the tree to traverse
 *
 * @func: Pointer to a function to call for each node.
 *
 * Return: If tree or func is NULL, do nothing
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
	{
		return;
	}

	if (func == NULL)
	{
		return;
	}

	/* Pass value to function pointer */
	func(tree->n);

	/* Recursivly order left and right branches with preorder */
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
