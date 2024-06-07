#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node in a binary tree
 * @node: pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node, or NULL if node is NULL,
 * has no parent, or the parent has no sibling
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandparent;

	if (node == NULL || node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);

	parent = node->parent;
	grandparent = parent->parent;

	if (grandparent->left == parent)
		return (grandparent->right);
	else if (grandparent->right == parent)
		return (grandparent->left);
	else
		return (NULL);
}
