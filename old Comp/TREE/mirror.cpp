TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL)
    return NULL;
    A->left=Solution::invertTree(A->left);
    A->right=Solution::invertTree(A->right);
    
    TreeNode *tr;
    tr=A->left;
    A->left=A->right;
    A->right=tr;
    
    return A;
    
}