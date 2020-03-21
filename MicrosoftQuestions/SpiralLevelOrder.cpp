//Level order traversal in spiral form
void printSpiral(Node *root)
{
    //Your code here
    if (!root) return;
    stack<Node*> lr,rl;
    rl.push(root);
    while (!rl.empty() || !lr.empty()){
        while(!rl.empty()){
        Node * current = rl.top();
        rl.pop();
        cout<<current->data<<" ";
        if (current->right)
         lr.push(current->right);
        if (current->left)
        lr.push(current->left);
    }
       while(!lr.empty()){
        Node * current = lr.top();
        lr.pop();
        cout<<current->data<<" ";
        if (current->left)
         rl.push(current->left);
         if (current->right)
        rl.push(current->right);
    }
    }
}
