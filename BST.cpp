#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};


struct node *search(struct node *root, int key)
{
    // if root is null or key is present at root node
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
    else
        return search(root->right, key);
}

struct node *newnode(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->left = temp->right = NULL;
    temp->data = value;
    return temp;
}
struct node *insert(struct node *node, int value)
{
    if (node == NULL)
    {
        return newnode(value);
    }
    else if (node->data > value)
    {
        node->left = insert(node->left, value);
    }
    else
        node->right = insert(node->right, value);
    return node;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
struct node *minvalue(struct node *node)
{
    struct node *current = node->left;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct node *deletenode(struct node *node, int key)
{
    if (node == NULL)
        return node;
    else if (node->data > key)
    {
        node->left = deletenode(node->left, key);
    }
    else if (node->data < key)
        node->right = deletenode(node->right, key);
    else
    { // no left child maybe right child
        if (node->left == NULL)
        {
            struct node *temp = node->right;
            free(node);
            return temp;
        } // left child may exist
        else if (node->right = NULL)
        {
            struct node *temp = node->left;
            free(node);
            return node;
        }

        struct node *temp = minvalue(node->right);
        node->data = temp->data;
        node->right = deletenode(node->right, temp->data);
    }
}
int main()
{
    struct node* root=NULL;
    root=insert(root,10);
    root=insert(root,35);
    root=insert(root,73);
    root=insert(root,11);
    root=insert(root,112);
    inorder(root);
}