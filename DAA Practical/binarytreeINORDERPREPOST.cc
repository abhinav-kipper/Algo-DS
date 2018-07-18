#include<iostream>
using namespace std;

struct node
{
    int  data;
    struct node * left;
    struct node * right;
};

//helper funciton initialize()

struct node * newNode(int data)
{
    struct node * node=new  struct node;
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
};
void preorder(struct  node * root)
{
    if (root==NULL)
        return;
    cout<<root->data<<"->";
    preorder(root->left);
    preorder(root->right);

}
void postorder(struct  node * root)
{
    if (root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"->";

}
void inorder(struct  node * root)
{
    if (root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<"->";
    inorder(root->right);

}
int main()
{
    struct node * root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right= newNode(5);

    cout<<"PREORDER"<<endl;
    preorder(root);
    cout<<"INORDER"<<endl;
    inorder(root);
    cout<<"POSTORDER"<<endl;
    postorder(root);


    return 0;
}
