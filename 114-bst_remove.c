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

	if (node == NULL)
	{
		return (NULL);
	}

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
		return (NULL);

	/* If node to delete smaller than root value, it is on left */
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	/* If node to delete greater than root value, it is on right */
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left && !root->right)
		{
			free(root);
			return (NULL);
		}
		else if (root->left != NULL || root->right != NULL)
		{
			temp = root;
			if (root->right)
				root = temp->right;
			else if (root->left)
				root = temp->left;
			if (temp->parent->left == temp)
				temp->parent->left = root;
			else
				temp->parent->right = root;
			root->parent = temp->parent;
			free(temp);
		}
		else
		{
			temp = min_value(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}
	return (root);
}
