#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 *
 * @tree:  Pointer to the root node of the tree to rotate
 *
 * Return: If tree is NULL, return 0, else  uncle
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node = NULL;

	if (tree == NULL || tree->right == NULL)
	{
		return (tree);
	}

	if (tree == NULL || tree->right == NULL)
		return (tree);
	node = tree->right;
	node->parent = tree->parent;
	tree->parent = node;
	tree->right = node->left;
	if (tree->right != NULL)
		tree->right->parent = tree;
	node->left = tree;
	return (node);
}
