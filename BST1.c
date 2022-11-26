#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node {
    int key;
    struct node *left,*right;
}node;

node* newNode(int value){
    node *temp=(node*)malloc(sizeof(node));
    scanf("%d",&value);
    temp->key=value;
    temp->left=temp->right=NULL;
    return temp;
}

node* insert(node *root,int value){
    if(root==NULL){
        return newNode(value);
    }

    else if(value>root->key){
        root->right=insert(root->right,value);
    }
    else 
    root->left=insert(root->left,value);

    return root;
}

void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

node *minvalue(struct node *node)
{
    struct node *current = node->left;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

int main(){
    // newNode();
    node* root=NULL;
    // printf("Enter any key to continue\n");
    root=insert(root,12);
    root=insert(root,2);
    root=insert(root,41);
    root=insert(root,164);
    root=insert(root,14);
    inorder(root);
}