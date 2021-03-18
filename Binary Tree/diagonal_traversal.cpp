#include <bits/stdc++.h>
using namespace std;


struct Node
{
	int data;
	Node *left;
	Node* right;

};
Node * newNode(int x)
{
	Node *t=new Node();
	t->data=x;
	t->left=t->right=NULL;
	return t;
}
void diagonalPrint(Node * root,map<int,vector<int>> &m,int s)
{
	if(!root)
		return;
	m[s].push_back(root->data);
	


	diagonalPrint(root->left,m,s+1);
	diagonalPrint(root->right,m,s);


	


}
int main()
{
	Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    /*  Node* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(9);
        root->left->right = newNode(6);
        root->right->left = newNode(4);
        root->right->right = newNode(5);
        root->right->left->right = newNode(7);
        root->right->left->left = newNode(12);
        root->left->right->left = newNode(11);
        root->left->left->right = newNode(10);*/
 	map<int,vector<int>> m;
    diagonalPrint(root,m,0);

    for(auto i:m)
    {
    	vector <int > v=i.second;
    	for(int j:v)
    	{
    		cout<<j<<" ";

    	}
    	cout<<endl;
    }

   
 
    return 0;
}