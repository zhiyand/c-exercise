#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

struct binaryTreeNode{
    char   tag;
    struct binaryTreeNode* left;
    struct binaryTreeNode* right;
};

typedef struct binaryTreeNode* BinaryTreeNode;

/**
 * Create a new node.
 */
BinaryTreeNode binary_tree_new_node(char tag);

/**
 * Attach `tag` to the `tree` on the `side` side.
 * - side: 1:left, 2:right
 */
void binary_tree_attach(BinaryTreeNode tree, BinaryTreeNode node, int side);

BinaryTreeNode binary_tree_detach(BinaryTreeNode tree, int side);

char* binary_tree_traversal(BinaryTreeNode tree, int order);

/*
 * Destroy `tree` and release all memory
 */
void binary_tree_destroy(BinaryTreeNode tree);


#endif // _BINARY_TREE_H_
