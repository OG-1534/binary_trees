#include <stddef.h>
#include "binary_trees.h"

int btih_helper(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int btic_helper(const binary_tree_t *tree, size_t index, size_t size);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - function that checks if a binary tree
 * is a valid Max Binary Heap
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap
 *         0 otherwise
 *         0 if tree is NULL
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btih_helper(tree));
}

/**
 * btih_helper - function that checks if a binary tree
 * is a valid Max Binary Heap
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap
 *         0 otherwise
 *         1 if tree is NULL
 */
int btih_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (btih_helper(tree->left) &&
		btih_helper(tree->right));
}

/**
 * binary_tree_is_complete - checks if a binary tree is a complete tree
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: if the tree is complete 1
 *         if the tree is not complete 0
 *         if tree is NULL 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (btic_helper(tree, 0, size));
}

/**
 * btic_helper - function that checks if a binary tree is a complete tree
 *
 * @tree: a pointer to the root node of the tree to check
 * @index: root node index to check
 * @size: number of nodes in the tree
 *
 * Return: if the tree is complete, 1
 *         if the tree is not complete, 0
 *         if tree is NULL, 0
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btic_helper(tree->left, 2 * index + 1, size) &&
		btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - function that measures the size of a binary tree
 *
 * @tree: tree to measure size of
 *
 * Return: size of the tree, if tree is NULL, 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
