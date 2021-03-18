#include <bits/stdc++.h> 
using namespace std; 
  
// A Binary Tree Node 
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
// Utility function to create a new tree node 
Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
Node *kthAncestorDFS(Node *root,int node,int &k)
{
	if(root==NULL)
		return NULL;
	if(root->data==node)
	{

		return root;
	}
	Node *l=kthAncestorDFS(root->left,node,k);
	if(!l)
	{

		Node*r=kthAncestorDFS(root->right,node,k);
		l=r;
	}
	if(l)
	{
		k--;
		if(k==0)
			l=root;
	}
	return l;

}
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create binary tree shown in above diagram 
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    int k = 0; 
    int node = 1; 
  
    // print kth ancestor of given node 
    Node* parent = kthAncestorDFS(root,node,k); 

    if(parent->data==node)
    	cout<<"-1 ";
    else
    cout<<parent->data<<" ";
      
      
    return 0; 
} 