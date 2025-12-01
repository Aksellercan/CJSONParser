#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

void Add_Root_To_Tree(struct BinaryTree **HEAD, char *left, char *right)
{
    //Reserve Memory
    struct BinaryTree *left_root = (struct BinaryTree*)malloc(sizeof(struct BinaryTree)*1);
    struct BinaryTree *right_root = (struct BinaryTree*)malloc(sizeof(struct BinaryTree)*1);
    struct BinaryTree *curr_root = *HEAD;
    //add left node
    left_root->root = left;
    left_root->left = NULL;
    left_root->right = NULL;

    //add right node
    right_root->root = right;
    right_root->left = NULL;
    right_root->right = NULL;

    curr_root->left = left_root;
    curr_root->right = right_root;
    *HEAD = curr_root;
    printf(":: Next root in tree: LEFT=%s and RIGHT=%s added\n", curr_root->left->root, curr_root->right->root);
}

void TraverseBinaryTree(struct BinaryTree* HEAD) {    
    struct BinaryTree *curr_root = HEAD;
    int count = 1;
    printf("");
    do {
        curr_root = curr_root->left;
        printf("%d: %s\n",count, curr_root->root );
        count++;
    } while(curr_root->left != NULL || curr_root->right != NULL);
}
