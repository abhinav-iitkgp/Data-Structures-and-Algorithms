#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node*left=NULL;
	node*right=NULL;
	
};

node *insert(node *root,int val)
{
	if(root==NULL)
	{
		node *t=new node ();
		t->data=val;
		return t;
	}
	if(root->data<val)
	{
		root->right=insert(root->right,val);

	}
	else if(root->data>val)
	{
		root->left=insert(root->left,val);

	}
	return root;

	
}
node * mini(node * root)
{
	if(root->left==NULL)
		return root;
	return mini(root->left);
}
node * deleteNode(node *root,int val)
{
	if(root==NULL)
		return root;
	if(root->data>val)
	{
		root->left=deleteNode(root->left,val);
			}
	else if(root->data<val)
	{
		root->right=deleteNode(root,val);
		
	}
	else
	{

		if(root->left==NULL)
		{
			node *t=root->right;
			free(root);
			return t;
		}
		else if(root->right==NULL)
		{
			free(root);
			return NULL;

		}
		else
		{
			node *t=mini(root->right);
			root->data=t->data;
			root->right=deleteNode(root->right,t->data);
		}

	}
	return root;

}
void inorder(node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main() 
{ 
    /* Let us create following BST 
            50 
        /     \ 
        30     70 
        / \ / \ 
    20 40 60 80 */
    node *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
    cout << "Inorder traversal of the given tree \n"; 
    inorder(root); 
  
    cout<<"\nDelete 20\n"; 
    root = deleteNode(root, 20); 
    cout<<"Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout<<"\nDelete 30\n"; 
    root = deleteNode(root, 30); 
    cout<<"Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout<<"\nDelete 50\n"; 
    root = deleteNode(root, 50); 
    cout<<"Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    return 0; 
} 