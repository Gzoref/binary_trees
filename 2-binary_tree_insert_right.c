#include "binary_trees.h"
/**
 * binary_tree_insert_left - creates a new binary branch on the left
 * @parent: Parent node
 * @value: Value of node
 * Return: Create a new Binary tree
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;


	if (parent == NULL)
		return (NULL);

	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->right = NULL;


	if (parent->right == NULL)
	{
		parent->right = node;
		node->right = NULL;
	}
	else
	{
		node->right = parent->right;
		parent->right->parent = node;
		parent->right = node;
	}
	return (node);
}
