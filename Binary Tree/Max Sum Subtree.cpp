#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left=NULL;
	Node* right=NULL;
	
};

Node * newNode(int n)
{

	Node* t=new Node();
	t->data=n;
	return t;

}
int sumUtill(Node* root,int &maxSum)
{
	if(root==NULL)
	{
		return 0;
	}
	
	int sum=root->data+sumUtill(root->left,maxSum)+sumUtill(root->right,maxSum);
	if(maxSum<sum)
	{

		maxSum=sum;
	}
	return sum;
}

int findLargestSubtreeSum(Node* root)
{
	int maxSum=INT_MIN;
	return sumUtill(root,maxSum);
}



int main() 
{ 
    /* 
               1 
             /   \ 
            /     \ 
          -2       3 
          / \     /  \ 
         /   \   /    \ 
        4     5 -6     2 
    */
  
    Node* root = newNode(1); 
    root->left = newNode(-2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(-6); 
    root->right->right = newNode(2); 
  
    cout << findLargestSubtreeSum(root)<<endl; 
    return 0; 
} 
