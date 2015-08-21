#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

struct binaryTreeNode{
    int    number;
    struct treeNode * left;
    struct treeNode * right;
};

typedef struct binaryTreeNode* BinaryTreeNode;

struct binaryTree{
    int levelCount;
    int nodeCount;
    BinaryTreeNode root;
};

typedef struct binaryTree* BinaryTree;

/*
 * Create a binary tree
 */
BinaryTree binary_tree_create();

/*
 * Insert `number` into the `tree`
 */
void binary_tree_insert(BinaryTree tree, int number);

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


#endif // _BINARY_TREE_H_
