#include "binary_trees.h"

/**
 * binary_tree_node - function to create a binary tree node.
 * @parent: pointer to the parent node of the new node to be created.
 * @value: value to be stored in the new node.
 * Return: Returns a pointer to the new node, or NULL if unsuccessful.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
