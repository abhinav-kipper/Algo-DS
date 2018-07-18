#include<iostream>
using namespace std;

struct node{
int key;
struct node *left,*right;
};

struct node * newNode(int item)
{
    struct node *temp=new node;
    temp->key=item;
    temp->left=temp->right=NULL;
    return temp;
};


struct node * minValueNode(struct node * node)
{
    struct node * current=node;
    while (current->left!=NULL)
        current=current->left;
    return current;
};
void inorder(struct node * root)
{
    if (root==NULL) return ;
    inorder(root->left);
    cout<<root->key<<"->";
    inorder(root->right);

}
//insert
struct node *insert(struct node *node,int key)
{
    //if tree is empty return new node
    if (node==NULL) return newNode(key);
    //otherwise
    if (key<node->key)
        node->left=insert(node->left,key);
    else
        node->right=insert(node->right,key);
    return node;//return the unchanged node pointer ROOT in the end
};

//delete
struct node * deleteNode(struct node * root,int  key)
{
    if (root==NULL) return root;
    if (key<root->key)
        root->left=deleteNode(root->left,key);
    else if (key>root->key)
        root->right=deleteNode(root->right,key);

    //key==root->key
    else{
        //node with only one child or no child
        if (root->left==NULL)
        {
            struct node * temp=root->right;
            delete root;
            return temp;
        }
        else if (root->right==NULL)
        {
            struct node * temp=root->left;
            delete root;
            return temp;
        }
        //node with two children: Get inorder successor to take  place
        struct node * temp=minValueNode(root->right);
        root->key=temp->key; //copy inorder succesor content to this node
        root->right=deleteNode(root->right,temp->key);//delete inorder successor
    }
    return root;
};

int main ()
{
    struct node *root=NULL;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,70);
    root=insert(root,60);
    root=insert(root,80);

    inorder (root);
    cout<<endl;
    root=deleteNode(root,20);
    inorder(root);
    cout<<endl;
    root=deleteNode(root,30);
    inorder(root);
    cout<<endl;
    root=deleteNode(root,50);
    inorder(root);
    cout<<endl;
}
