

// make a path matrix and initialize with 0;
// make a recursive function that recieves the rat(i,j) position 
// if (i,j) not valid position then return
// make path[i][j]=1;
// if on rat is on destination "print " the path matrix and return;
// call recusive function for (i+1),j  and i,(j+1)
// unmark position (i,j) i.e path[i][j]=0
// return;



#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> path;

bool goodtobe(int a[][4],int i,int j)
{
	if(i>=0&&i<n&&j>=0&&j<n&&a[i][j]==1)
	return true;
	else
		return false;
}
void print()
{
	for(int i=0;i<n;i++)
		{
			for(int j: path[i])
			{
				cout<<j<<" ";

			}
			cout<<endl;
		}

}

void rat_maze(int a[][4],int i,int j)
{
	if(!goodtobe(a,i,j))
		return;
	path[i][j]=1;

	if(i==n-1&&j==n-1)
	{
		print();
		return;
	}

	rat_maze(a,i,j+1);
	rat_maze(a,i+1,j);

	path[i][j]=0;
	return;
}





int main()
{
	n=4;
	int A[4][4] = { { 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } }; 

    
	vector<vector<int> >path1(n,vector<int>(n,0));
	path=path1;

	rat_maze(A,0,0);
	



}