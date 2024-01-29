#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
    element data;
    struct TreeNode *left, *right;
} TreeNode;

//중위순회(LVR)
void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("[%d]", root->data);
        inorder(root->right);
    }
}

//전위순회(VLR)
void preorder(TreeNode *root)
{
    if (root != NULL)
    {
        printf("[%d]", root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

//후위순회(LRV)
void postorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        inorder(root->right);
        printf("[%d]", root->data);
    }
}

int main(void)
{
    //      15
    //  4       20
    //1     16      25
    TreeNode n1 = {1, NULL, NULL};
    TreeNode n2 = {4, &n1, NULL};
    TreeNode n3 = {16, NULL, NULL};
    TreeNode n4 = {25, NULL, NULL};
    TreeNode n5 = {20, &n3, &n4};
    TreeNode n6 = {15, &n2, &n5};
    TreeNode *root = &n6;

    printf("중위순회\n");
    inorder(root);
    printf("\n");

    printf("전위순회\n");
    preorder(root);
    printf("\n");

    printf("후위순회\n");
    postorder(root);
    printf("\n");

    return 0;
}