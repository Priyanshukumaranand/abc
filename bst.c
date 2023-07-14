// C program to implement optimized delete in BST.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int key;
    struct Node *left, *right;
};
struct Node *root = NULL;
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

/* A utility function to insert a new node with given key in
 * BST */
struct Node *insert(struct Node *node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL){
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node*));
        temp->key = key;
        temp->left = temp->right = NULL;
        return temp;
    }

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}
/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
struct Node *deleteNode(struct Node *root, int k)
{
    // Base case
    if (root == NULL)
        return root;

    // Recursive calls for ancestors of
    // node to be deleted
    if (root->key > k)
    {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->key < k)
    {
        root->right = deleteNode(root->right, k);
        return root;
    }

    // We reach here when root is the node
    // to be deleted.

    // If one of the children is empty
    if (root->left == NULL)
    {
        struct Node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        struct Node *temp = root->left;
        free(root);
        return temp;
    }

    // If both children exist
    else
    {
        struct Node *succParent = root;

        // Find successor
        struct Node *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        // Delete successor. Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        // Copy Successor Data to root
        root->key = succ->key;

        // Delete Successor and return root
        free(succ);
        return root;
    }
}
int main()
{
    /* Let us create following BST
            50
        /	 \
        30	 70
        / \ / \
    20 40 60 80 */
    // root = insert(root, 50);
    // root = insert(root, 30);
    // root = insert(root, 20);
    // root = insert(root, 40);
    // root = insert(root, 70);
    // root = insert(root, 60);
    // printf("Original BST: ");
    // inorder(root);
    int data;
    while (1)
    {
        int choice;
        printf("1.INSERT\n2.DELETE\n3.TRAVERSE\n0.EXIT\nEnter your choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter data to insert:");
            scanf("%d", &data);
            root = insert(root, data);
        }
        else if (choice == 2)
        {
            printf("Enter data you want to delete:");
            scanf("%d", &data);
            root = deleteNode(root, data);
        }
        else if (choice == 3)
        {
            printf("PREORDER : ");
            preorder(root);
            printf("\n");
            printf("INORDER : ");
            inorder(root);
            printf("\n");
            printf("POSTORDER : ");
            postorder(root);
            printf("\n");
        }
        else
            break;
    }
    // int ****p2;
    // int *p1=&p2;
    // p2=&p1;
    // // printf("%d\n",sizeof(p1));
    //  printf("%d\n",sizeof(*p2));
    // // printf("%x\n",p1);
    // // printf("%x\n",&p1);
    // printf("%x\n",p2);
    // printf("%x\n",*p2);
    // printf("%x\n",***p2);
    // int p=2147483648;
    // printf("%d",p);
    return 0;
}
