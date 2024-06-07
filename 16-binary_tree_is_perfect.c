#include "binary_trees.h"

/**
 * binary_tree_height_s - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of tree
 */
size_t binary_tree_height_s(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = binary_tree_height_s(tree->left) + 1;
	right_height = binary_tree_height_s(tree->right) + 1;

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

/**
 * binary_tree_is_perfect - check if tree is perfect
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 for perfect tree else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, expected_nodes;

	if (tree == NULL)
		return (0);

	height = binary_tree_height_s(tree);
	expected_nodes = (1 << (height + 1)) - 1;

	return (binary_tree_size(tree) == expected_nodes);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return ((left_size + right_size) + 1);
}
