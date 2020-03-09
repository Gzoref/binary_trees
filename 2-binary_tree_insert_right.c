#include "binary_trees.h"

/**
 * binary_tree_insert_right - Creates a binary tree node
 *
 * @parent: Parent node
 *
 * @value: Value of node
 *
 * Return: Create new Binary tree
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));


	if (new_node == NULL)
	{
		return (NULL);
	}


	if (parent == NULL)
	{
		return (NULL);
	}

	new_node->parent = parent;
	new_node->n = value;
	new_node->right = parent->right;

	if (parent->right)
	{
		new_node->right->parent = new_node;

	}
	parent->right = new_node;
	return (new_node);
}
