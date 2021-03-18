#include <bits/stdc++.h>
using namespace std;
class node 
{
public:
    int data;
    node* left;
    node* right;
};
 
// A utility function to create a node
node* newNode(int data)
{
    node* temp = new node();
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}

int findGreater(int pre[],int size)
{
	int j;
	for(j=1;j<size;j++)
	{
		if(pre[j]>pre[0])
			return j;
	}
	return j;
}
// O(n^2)
// int findGreater(int pre[],int size)
// {
// 	int j;
// 	for(j=1;j<size;j++)
// 	{
// 		if(pre[j]>pre[0])
// 			return j;
// 	}
// 	return j;
// }
// node * constructTree(int pre[],int size)
// {
// 	if(size==0)
// 		return NULL;
	

// 	node* t=newNode(pre[0]);
// 	int i=findGreater(pre,size);
// 	t->left=constructTree(pre+1,i-1);
// 	t->right=constructTree(pre+i,size-i);
// 	return t;
// }

//O(n)
node * constTree(queue<int> &q,int l,int r)
{
	if(q.empty())
		return NULL;
	int root=q.front();
	

	if(l<root&&root<r)
	{
		node *t=newNode(root);
		q.pop();
		t->left=constTree(q,l,root);
		t->right=constTree(q,root,r);
		return t;
	}
	
	return NULL;

}
node *constructTree(int pre[],int size)
{
	int l=INT_MIN;
	int r=INT_MAX;
	queue<int> q;
	for(int i=0;i<size;i++)
	{
		q.push(pre[i]);
	}
	return constTree(q,l,r);
}
void printInorder(node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main()
{
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);
 
    // Function call
    node* root = constructTree(pre, size);
 
    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);
 
    return 0;
}