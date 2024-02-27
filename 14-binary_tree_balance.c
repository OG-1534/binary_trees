#include "binary_trees.h"

/**
 * binary_tree_height_bal - function that measures height of a binary tree
 * for a balance factor
 *
 * @tree: pointer to the root node of the tree
 * to go through for balance factor
 *
 * Return: height of binary tree
 */

size_t binary_tree_height_bal(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height_bal(tree->left) : 1;
			r = tree->right ? 1 + binary_tree_height_bal(tree->right) : 1;
		}
		return ((l > r) ? l : r);
	}
}

/**
 * binary_tree_balance - function that measures the balance factor
 * of a binary tree
 *
 * @tree: pointer to the root node of the tree
 * to measure the balance factor
 *
 * Return: balance factor, if tree is NULL, return 0.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)binary_tree_height_bal(tree->left));
		right = ((int)binary_tree_height_bal(tree->right));
		total = left - right;
	}
	return (total);
}
