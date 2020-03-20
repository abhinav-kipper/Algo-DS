//Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes in any level.
int height(Node * root){
    if (!root) return 0;
    return max(height(root->left), height(root->right))+1;
}

void maxWidthPreOrder(int * count, Node * root, int level){
    if (!root) return;
    count[level]++;
    maxWidthPreOrder(count, root->left,level+1);
    maxWidthPreOrder(count, root->right,level+1);
    
}
int getMaxWidth(Node* root)
{
    
   // Your code here
   int h = height(root);
   int *count = new int[h]; 
   for (int i=0;i<h;i++)
        count[i]=0;
   maxWidthPreOrder(count, root, 0);
   int maxWidth = 0;
   for (int i=0;i<h;i++)
        maxWidth = max(count[i], maxWidth);
    return maxWidth;
}

