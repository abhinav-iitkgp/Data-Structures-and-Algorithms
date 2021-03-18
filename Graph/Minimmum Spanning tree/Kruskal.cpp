

// 1. Sort all the edges in non-decreasing order of their weight.
// 2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.
// 3. Repeat step#2 until there are (V-1) edges in the spanning tree.



#include<bits/stdc++.h>
using namespace std;
int *id;
int root(int a)
{
	while(a!=id[a])
	{
		id[a]=id[id[a]];
		a=id[a];
	}
	return a;
}
void union_(int a,int b)
{
	a=root(a);
	b=root(b);
	id[a]=id[b];
}

int mst(pair<int,pair<int,int>> edges[],int e)
{
	int m=0,a,b;
	for(int i=0;i<e;i++)
	{
		a=edges[i].second.first;
		b=edges[i].second.second;

		if(root(a)!=root(b))
		{
			m+=edges[i].first;
			union_(a,b); 

		}

	}
	return m;
}


int main()
{
//input
//6 9
// 0 3 5 
// 0 2 4 
// 0 1 4
// 1 4 11
// 1 2 1
// 4 2 10
// 4 5 3
// 2 5 3
// 5 3 21

//output
//16


#ifndef o
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
	#endif

	
	
	int n,e;
	cin>>n>>e;
	int x,y,weight;
	

	pair<int,pair<int,int>> edges[e];
	for(int i=0;i<e;i++)
	{
		cin>>x>>y>>weight;
		edges[i]=make_pair(weight,make_pair(x,y));

	}
	int id1[n];
	for(int i=0;i<n;i++)
	{
		id1[i]=i;
	}

	id=id1;
	

	sort(edges,edges+e);

	int minimum_cost=mst(edges,e);
	cout<<minimum_cost;







}