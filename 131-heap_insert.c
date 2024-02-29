#include "binary_trees.h"

/**
 * heap_insert - function that inserts a value in Max Binary Heap
 *
 * @root: a double pointer to the root node of the Heap
 * to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node,
 * or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;
	/* apart from bottom-most level subtract all nodes */

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;
	/*
	 * Traverse tree to first empty slot based on the binary
	 * rep. of the no. of leaves.
	 * Ex. If there are 12 nodes in a complete tree,
	 * there are 5 leaves on the 4th tier of the tree.
	 * 5 is 101 in binary. 1 corresponds to right, 0 to left.
	 * The first empty node is 101 == RLR,
	 * root->right->left->right
	 */

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}
	/* Until parent value exceeds new value flip values with parent */

	return (new);
}

/**
 * binary_tree_size - function that measures the size of a binary tree
 *
 * @tree: binary tree to measure the size of
 *
 * Return: size of the tree, or if tree is NULL, 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
