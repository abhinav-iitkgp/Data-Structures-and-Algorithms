#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node * left,*right;
	Node(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}

};

pair<int,int> maxUtill(Node* root)
{
	if(root==NULL)
	{
		return {0,0};
	}

	pair<int,int> l=maxUtill(root->left);
	pair<int,int> r=maxUtill(root->right);
	pair<int,int> sum;

	sum.first=root->data+l.second+r.second;

	sum.second=max(l.first,l.second)+max(r.first,r.second);

	return sum;



}


int maxSum(Node *root)
{
	pair<int,int> m=maxUtill(root);
	return max(m.first,m.second);
}
int main() 
{ 
    // Node *root= new Node(10); 
    // root->left= new Node(1); 
    // root->left->left= new Node(2); 
    // root->left->left->left= new Node(1); 
    // root->left->right= new Node(3); 
    // root->left->right->left= new Node(4); 
    // root->left->right->right= new Node(5);



	Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->right->left = new Node(4); 
    root->right->right = new Node(5); 
    root->left->left = new Node(1); 
     cout << maxSum(root); 
    return 0; 
} 