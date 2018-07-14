#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary-tree.h"



/*
 * Destroy `tree` and release all memory
 */
void binary_tree_destroy(BinaryTreeNode tree);

/* ------------ */

BinaryTreeNode binary_tree_new_node(char tag)
{
    BinaryTreeNode node = (BinaryTreeNode) malloc(sizeof(struct binaryTreeNode));

    node->tag = tag;
    node->left   = NULL;
    node->right  = NULL;

    return node;
}

/**
 * Attach `tag` to the `tree` on the `side` side.
 * - side: 1:left, 2:right
 */
void binary_tree_attach(BinaryTreeNode tree, BinaryTreeNode node, int side)
{
    if (side == 1) {
        tree->left = node;
    } else {
        tree->right = node;
    }
}

BinaryTreeNode binary_tree_detach(BinaryTreeNode tree, int side)
{
    return side == 1 ? tree->left : tree->right;
}

/**
 * - order: 1:pre-order, 2:in-order, 3:post-order
 */
char* binary_tree_traversal(BinaryTreeNode tree, int order)
{
    if (tree->left == NULL && tree->right == NULL) {
        char* s = (char*) malloc(2);
        sprintf(s, "%c", tree->tag);
        return s;
    }

    char* left = tree->left == NULL ? "" : binary_tree_traversal(tree->left, order);
    char* right = tree->right == NULL ? "" : binary_tree_traversal(tree->right, order);

    size_t length = 2 + strlen(left) + strlen(right);
    char* buffer = (char*) malloc(length);
    memset((void*)buffer, 0, length);


    switch(order){
        case 1:
            sprintf(buffer, "%c%s%s", tree->tag, left, right);
            break;
        case 2:
            sprintf(buffer, "%s%c%s", left, tree->tag, right);
            break;
        case 3:
            sprintf(buffer, "%s%s%c", left, right, tree->tag);
            break;
    }

    return buffer;
}

