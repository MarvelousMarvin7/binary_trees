#include "binary_trees.h"

/**
 * binary_tree_heights - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of tree
 */
size_t binary_tree_heights(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (-1);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = binary_tree_heights(tree->left) + 1;
	right_height = binary_tree_heights(tree->right) + 1;

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance.
 *
 * Return: balance factor of tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_heights(tree->left) -
		binary_tree_heights(tree->right));
}
