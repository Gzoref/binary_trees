#include "binary_trees.h"

/**
 * min_value - Return minmax values
 * @node:  Pointer to the root node of the tree to rotate
 * Return: 1 if BST, 0 if not
 */

bst_t *min_value(bst_t *node)
{
       /* Loop to find leftmost node */
	bst_t *current = node;

	while (current && current->left != NULL)
	{
		current = current->left;
	}
	return (current);
}

/**
 * bst_remove - Removes a node in a Binary Search Tree
 * @root: Pointer to root node of BST
 * @value: Value to be found
 * Return: A pointer to new root node, or NULL on failure
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (root == NULL)
	{
		return (NULL);
	}

	/* If node to delete smaller than root value, it is on left */
	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	/* If node to delete greater than root value, it is on right */
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
	}
	/* If value is root's value, delete node */
	else
	{
		/* Node has one or no children */
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		/* Node with two children */
		temp = min_value(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
