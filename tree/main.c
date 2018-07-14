#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary-tree.h"

int strpos(char* stack, char needle, int limit);
BinaryTreeNode reconstruct(char* pre, char* in, int n);

int main(void){

    BinaryTreeNode A = binary_tree_new_node('A');
    BinaryTreeNode B = binary_tree_new_node('B');
    BinaryTreeNode C = binary_tree_new_node('C');
    BinaryTreeNode D = binary_tree_new_node('D');
    BinaryTreeNode E = binary_tree_new_node('E');
    BinaryTreeNode F = binary_tree_new_node('F');

    binary_tree_attach(A, B, 1);
    binary_tree_attach(A, C, 2);
    binary_tree_attach(B, F, 1);
    binary_tree_attach(C, D, 1);
    binary_tree_attach(C, E, 2);

    char* pre_order = binary_tree_traversal(A, 1);
    char* in_order = binary_tree_traversal(A, 2);
    char* post_order = binary_tree_traversal(A, 3);

    printf("Pre-order:%s\n", pre_order);
    printf("In-order:%s\n", in_order);
    printf("Post-order:%s\n", post_order);

    /* Reconstruct the tree from its pre-order and in-order transversal */

    BinaryTreeNode tree = reconstruct(pre_order, in_order, strlen(pre_order));

    printf("Reconstructed\n");
    printf("Pre-order:%s\n", binary_tree_traversal(tree, 1));
    printf("In-order:%s\n", binary_tree_traversal(tree, 2));
    printf("Post-order:%s\n", binary_tree_traversal(tree, 3));

    return 0;
}

int strpos(char* stack, char needle, int limit)
{
    int i = 0;
    int min = strlen(stack) < limit ? strlen(stack) : limit;
    for(i = 0; i < min; i++){
        if (stack[i] == needle) {
            return i;
        }
    }
    return -1;
}

char* substr(char* str, int offset, int length) {
    char* buffer = (char*) malloc(length+1);

    for (int i = 0; i < length; i++) {
        buffer[i] = str[offset + i];
    }
    buffer[length+1] = '\0';

    return buffer;
}

BinaryTreeNode reconstruct(char* pre, char* in, int n)
{
    BinaryTreeNode root = binary_tree_new_node(pre[0]);
    if (n == 1) {
        return root;
    }

    int split = strpos(in, pre[0], n);

    int n_L = split;
    int n_R = n - split - 1;

    char* in_L = substr(in, 0, n_L);
    char* in_R = substr(in, split + 1, n_R);
    char* pre_L = substr(pre, 1, n_L);
    char* pre_R = substr(pre, 1 + n_L, n_R);

    BinaryTreeNode left = n_L == 0 ? NULL : reconstruct(pre_L, in_L, n_L);
    BinaryTreeNode right = n_R == 0 ? NULL : reconstruct(pre_R, in_R, n_R);

    root->left = left;
    root->right = right;

    return root;
}

