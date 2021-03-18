#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node * newNode(int d)
{
	Node *t=new Node();
	t->data=d;
	t->left=t->right=NULL;

	return t;

}
int bracketClose(string s,int i,int j)
{
	stack<char> st;
	for(int k=i;k<=j;k++)
	{
		if(s[k]==')'&&st.top()=='(')
			st.pop();
		else if(s[k]=='(')
			st.push('(');
		else if(s[k]==')')
			st.push(')');
		if(st.empty())
		{
			return k;
		}

	}
	return -1;
}
Node* createTree(string s,int i,int j)
{

	if(i>j)
		return NULL;

	
	
	Node *root=newNode(s[i]-'0');
	int x=bracketClose(s,i+1,j);

	if(x!=-1)
		
	{

	

	root->left=createTree(s,i+2,x-1);
	root->right=createTree(s,x+2,j-1);
	}

	return root;

}

void prtPreorder(Node *root)
{
	if(root==NULL)
	{
		return;
	}

	prtPreorder(root->left);
	cout<<root->data<<" ";
	prtPreorder(root->right);


}


int main()
{
	string s="4(2(3)(1))(6(5))";

	Node * root=createTree(s,0,s.length()-1);
	prtPreorder(root);

}

