#include <stdlib.h>
#include "binary-tree.h"

/*
 * Create a binary tree
 */
BinaryTree binary_tree_create(){
    BinaryTree tree = (BinaryTree) malloc(sizeof(struct binaryTree));

    tree->levelCount = 0;
    tree->nodeCount  = 0;
    tree->root       = NULL;

    return tree;
}

static BinaryTreeNode binary_tree_node_create(int number){
    BinaryTreeNode node = (BinaryTreeNode) malloc(sizeof(struct binaryTreeNode));

    node->number = number;
    node->left   = NULL;
    node->right  = NULL;

    return node;
}

/*
 * Insert `number` into the `tree`
 */
void binary_tree_insert(BinaryTree tree, int number)
{
    BinaryTreeNode node = tree->root;

    if(tree->root == NULL){
        tree->root = binary_tree_node_create(number);
        return;
    }

    
}

/*
 * Find `number` in `tree`
 *
 * @return the corresponding BinaryTreeNode if found;
 *         NULL if not found.
 */
BinaryTreeNode binary_tree_search(BinaryTree tree, int number);

/*
 * Delete `number` from `tree`
 */
void binary_tree_delete(BinaryTree tree, int number);

/*
 * Display `tree` on screen
 */
void binary_tree_display(BinaryTree tree);

/*
 * Destroy `tree` and release all memory
 */
void binary_tree_destroy(BinaryTree tree);

