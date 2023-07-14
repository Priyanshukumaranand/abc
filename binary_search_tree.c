#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *insert_into_bst(struct node *root, int data)
{
    if (root == NULL)
    {
        struct node *node;
        node = (struct node *)malloc(sizeof(struct node *));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    if (data > root->data)
        root->right = insert_into_bst(root->right, data);
    else if (data < root->data)
        root->left = insert_into_bst(root->left, data);
    return root;
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d \n", root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d \n", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d \n", root->data);
}
void delete()
{
}
int main()
{
    int data=0;
    while (data != -1)
    {
        printf("Enter data:");
        scanf("%d", &data);
        root = insert_into_bst(root, data);
    }
    printf("inorder\n");
    inorder(root);
    printf("preorder\n");
    preorder(root);
    printf("postorder\n");
    postorder(root);
  //  printf("%d", root->data);
    return 0;
}