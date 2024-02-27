#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * @node: Node to check.
 *
 * Return: 1 if the node is a leaf,
 *         0 if the node is not a leaf,
 *         0 if the node is NULL.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return ((!node || node->left || node->right) ? 0 : 1);
}
