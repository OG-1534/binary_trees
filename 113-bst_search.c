#include "binary_trees.h"
/**
 * bst_search - function that searches for a value
 * in a Binary Search Tree.
 *
 * @tree: pointer to the root node of the BST to search.
 * @value: value to search in the tree.
 *
 * Return: pointer to the node value equals to value,
 * NULL if tree is NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{

	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
	return (NULL);
}
