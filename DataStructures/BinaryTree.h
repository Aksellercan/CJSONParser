#ifndef BinaryTree_H_
#define BinaryTree_H_

struct BinaryTree{
    struct BinaryTree *left;
    char* root;
    struct BinaryTree *right;
};

void Add_Root_To_Tree(struct BinaryTree **HEAD, char *left, char *right);
void TraverseBinaryTree(struct BinaryTree *HEAD);

#endif
