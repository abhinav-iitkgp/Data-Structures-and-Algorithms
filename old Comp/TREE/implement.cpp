
#include <bits/stdc++.h>


using namespace std;

struct BstNode
{
	int data;
	BstNode *left;
	BstNode *right;
};
BstNode*GetNewNode(int data)
{
	 BstNode* newode=new BstNode();
	 // (*newode).data=data;
	 newode->data=data;
	 newode->left=newode->right=NULL;
	 return newode;

}

BstNode* insert(BstNode*root,int data)
{
	if(root==NULL)
		{
			root=GetNewNode(data);
			return root;

		}
		else if( data<=root->data)
		{
			root->left= insert(root->left,data);

		}
		else
		{
			root->right= insert(root->right,data);

		}
		return root;



}
bool search(BstNode*root ,int data)
{
	if(root==NULL)
		return false;
	else if(root->data==data)
		return true;
	else if(data<=(root->data))
	{
		return search(root->left,data);


	}
	else
		return search(root->right,data);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	BstNode* root;
 	root=NULL;

 	root=insert(root,10);
 	root=insert(root,14);
 	root=insert(root,12);
 	root=insert(root,5);
 	root=insert(root,1000);
 	root=insert(root,99);
 	root=insert(root,-2);
 	root=insert(root,6);
 	root=insert(root,-213);
 	root=insert(root,141);
 	root=insert(root,121);
 	root=insert(root,52);
 	root=insert(root,100);
 	root=insert(root,992);
 	root=insert(root,-23);
 	root=insert(root,63);
 	int n;

 	
 	cin>>n;
 	if(search(root,n))
 		cout<<"FOUND";
 	else
 		cout<<"NOT FOUND";
 	cout<<endl;



}

