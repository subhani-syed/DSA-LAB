#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void inorder(struct node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}
struct node *insert(struct node *node, int data)
{
    if (node == NULL)
        return newnode(data);
    else
    {
        if (data < node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        return node;
    }
}
struct node *min(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct node *delete (struct node *node, int data)
{
    if (node == NULL)
        return node;
    if (data < node->data)
        node->left = delete (node->left, data);
    else if (data > node->data)
        node->right = delete (node->right, data);
    else
    {
        if (node->left == NULL)
        {
            struct node *temp = node->right;
            free(node);
            return temp;
        }
        struct node *temp = min(node->right);
        node->data = temp->data;
        node->right = delete (node->right, temp->data);
    }
    return node;
}
struct node *search(struct node *node, int data)
{
    if (node == NULL)
    {
        printf("Element not found\n");
        return node;
    }
    if (data < node->data)
        node->left = search(node->left, data);
    else if (data > node->data)
        node->right = search(node->right, data);
    else if (data == node->data)
        printf("Element found\n");
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 6);
    inorder(root);
    printf("\n");
    printf("After deleting 5\n");
    root = delete (root, 5);
    inorder(root);
    printf("\n");
    search(root, 5);
    search(root, 8);
}