#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
    element key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* search(TreeNode *node, element key)
{
    if (node == NULL) return NULL;
    if (key == node->key) return node;
    else if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode* new_node(int item)
{
    TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
    new->key = item;
    new->left = NULL;
    new->right = NULL;
    return new;
}

TreeNode* insert_node(TreeNode *node, int key)
{
    if (node == NULL) return new_node(key);

    if (key < node->key)
        node->left = insert_node(node->left, key);
    else
        node->right = insert_node(node->right, key);

    return node;
}

TreeNode* min_value_node(TreeNode *node)
{
    TreeNode *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

TreeNode* delete_node(TreeNode *root, int key)
{
    if (root == NULL) return NULL;

    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    else {
        if (root->left == NULL)
        {
            TreeNode *tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == NULL)
        {
            TreeNode *tmp = root->left;
            free(root);
            return tmp;
        }
        else
        {
            TreeNode *tmp = min_value_node(root->right);
            root->key = tmp->key;
            root->right = delete_node(root->right, tmp->key);
        }
    return root;
    }
}

void inorder(TreeNode *root)
{
    if (root) {
        inorder(root->left);
        printf("[%d]", root->key);
        inorder(root->right);
    }
}

int main(void)
{
    TreeNode *root = NULL;

    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);
    
    printf("이진 탐색 트리 중위 순회 결과 \n");
    inorder(root);
    printf("\n\n");

    if (search(root,30) != NULL)
        printf("이진 탐색 트리에서 30 발견\n");
    else
        printf("이진 탐색 트리에서 30 발견 못함\n");
    
    root = delete_node(root, 30);
    if (search(root,30) != NULL)
        printf("이진 탐색 트리에서 30 발견\n");
    else
        printf("이진 탐색 트리에서 30 발견 못함\n");
    return 0;
}