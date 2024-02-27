#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a root.
 * @node: Node to check.
 *
 * Return: 1 if the node is a root,
 *         0 if the node is not a root,
 *         0 if the node is NULL.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return ((!node || node->parent) ? 0 : 1);
}
