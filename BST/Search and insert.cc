#include<bits/stdc++.h>
struct node
{
    int key;
    struct node *left,*right;
};

//--------BST Node Creation function
struct node *newNode (int item)
{
    struct node *temp= (struct node *) mallocc (sizeof(struct node));
    temp->key=item;
    temp->left=temp->right=NULL;
    return temp;
} ;


//inorder traversal
void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
         cout<<endl<<root->key;
         inorder(root->right);
    }
}
strut node* insert(struct node* node,int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left,key);
    else if (key > node->key)
        node->right=insert(node->right,key);
    return node;
}
{

}
