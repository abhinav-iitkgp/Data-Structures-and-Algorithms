int t;
int find(Node *root)
{
    if(root==NULL)
    return -1;
    int x=find(root->left);
    if(x==-1)
    {
        t--;
        if(t==0)
        return root->data;
        x=find(root->right);
        
        
    }
    return x;
}

int KthSmallestElement(Node *root, int K)
{
    t=K;
    return find(root);
}