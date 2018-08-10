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
