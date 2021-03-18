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
void print_(queue<int> q)
{
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
	return;
}

void print_vector(vector<int> path,int i)
{
	for(int j=i;j<path.size();j++)
	{
		cout<<path[j]<<" ";
	}
	cout<<endl;

}
 
void prtUtill(Node *root,vector<int> &path,int k)
{
	if(root==NULL)
		return;
	path.push_back(root->data);
	prtUtill(root->left,path,k);
	prtUtill(root->right,path,k);
	
	int sum=0;
	for(int i=path.size()-1;i>=0;i--)
	{
		sum=sum+path[i];

		if(sum==k)
		{
			print_vector(path,i);
		}

	}
	

	path.pop_back();
	

}
void printKPath(Node *root,int k)
{
	vector<int> path;
	prtUtill(root,path,k);
}



int main() 
{ 
    Node *root = new Node(1); 
    root->left = new Node(3); 
    root->left->left = new Node(2); 
    root->left->right = new Node(1); 
    root->left->right->left = new Node(1); 
    root->right = new Node(-1); 
    root->right->left = new Node(4); 
    root->right->left->left = new Node(1); 
    root->right->left->right = new Node(2); 
    root->right->right = new Node(5); 
    root->right->right->right = new Node(2); 
  
    int k = 5; 
    printKPath(root, k); 
  
    return 0; 
}