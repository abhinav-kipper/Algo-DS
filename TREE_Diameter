//geeks
int mxheight(Node * node)
{
     if (!node) return 0;
     return 1+max(mxheight(node->left),mxheight(node->right));
}
int diameter(Node* node)
{
    if (!node) return 0;   
    int l_height=mxheight(node->left);
    int r_height=mxheight(node->right);
    int l_diameter=diameter(node->left);
    int r_diameter=diameter(node->right);
    
    return max(l_height+r_height+1,max(l_diameter,r_diameter));
}
