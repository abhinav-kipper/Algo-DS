//Given values of two values n1 and n2 in a Binary Search Tree, find the Lowest Common Ancestor (LCA). 
//You may assume that both the values exist in the tree.
Node* LCA(Node *root, int n1, int n2)
{if (!root) return NULL;
    
   //Your code here
   if ((root->data>=n1 && root->data<=n2) ||(root->data<=n1 && root->data>=n2)) {
       return root;
   }
   else if (root->data>= n1 && root->data>=n2){
       return LCA(root->left, n1, n2);
   }
   else  return LCA(root->right, n1,n2);
}

//Little Clean Code
struct node *lca(struct node* root, int n1, int n2) 
{ 
    if (root == NULL) return NULL; 
  
    // If both n1 and n2 are smaller than root, then LCA lies in left 
    if (root->data > n1 && root->data > n2) 
        return lca(root->left, n1, n2); 
  
    // If both n1 and n2 are greater than root, then LCA lies in right 
    if (root->data < n1 && root->data < n2) 
        return lca(root->right, n1, n2); 
  
    return root; 
} 
