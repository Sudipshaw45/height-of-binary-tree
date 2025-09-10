#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(struct Node* root) {
    if (root == NULL)
        return -1; 

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main() {
   
    struct Node* root = newNode(12);
    root->left = newNode(8);
    root->right = newNode(18);
    root->left->left = newNode(5);
    root->left->right = newNode(11);

    printf("Height of the binary tree is: %d\n", height(root));

    return 0;
}
