#include <bits/stdc++.h>

using namespace std;

struct tree
{
	int data;
	tree* left;
	tree* right;

};
tree * insert(tree * root,int data)
{
	if(root==NULL)
	{
		tree* tr=new tree();
		tr->data=data;
		tr->left=tr->right=NULL;
		return tr;

	}



	else if(data<=root->data)
	{
		root->left=insert(root->left,data);

	}
	else if(data>root->data)
	{
		root->right=insert(root->right,data);

	}
	return root;

}

void inorderprt(tree* root)
{
	if(root==NULL)
		return;


	inorderprt(root->left);
	cout<<root->data<<" ";
	inorderprt(root->right);



}





int main()
{
	#ifndef o
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	tree *root;
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
 	
 	

 	inorderprt(root);
 	
 	



	




}