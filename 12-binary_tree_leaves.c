#include "binary_trees.h"

/**
 * binary_tree_is_leaf - fumction that checks if a node is a leaf.
 *
 * @node: pointer to the node to check.
 *
 * Return: 1 if node is a leaf, if node is NULL, return 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->right == NULL && node->left == NULL)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_leaves - function that counts the leaves in a binary tree.
 *
 * @tree: pointer to the root node of the tree to count the number of leaves.
 *
 * Return: number of leaves, or if tree is NULL, 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (binary_tree_is_leaf(tree) +
			binary_tree_leaves(tree->right) +
			binary_tree_leaves(tree->left));
}
