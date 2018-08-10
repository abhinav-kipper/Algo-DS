 bool check(Node * root,int min,int max)
 {
     if (!root) return true;
     
     if  (root->data<min || root->data>max) return false;
     
     return (check(root->left,min,root->data-1) &&
            check(root->right,root->data+1,max));
 }
bool isBST(Node* root) {
    // Your code here
   return check(root,INT_MIN,INT_MAX);
}
//same but using  null pointer
bool isBST(Node* root, Node* l=NULL, Node* r=NULL)
{
    // Base condition
    if (root == NULL)
        return true;
 
    // if left node exist then check it has
    // correct data or not i.e. left node's data
    // should be less than root's data
    if (l != NULL and root->data < l->data)
        return false;
 
    // if right node exist then check it has
    // correct data or not i.e. right node's data
    // should be greater than root's data
    if (r != NULL and root->data > r->data)
        return false;
 
    // check recursively for every node.
    return isBST(root->left, l, root) and
           isBST(root->right, root, r);
}
