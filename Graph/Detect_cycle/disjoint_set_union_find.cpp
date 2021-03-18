// disjoint set is used to find cycle in an undirected graph
// we use 1 d array
// let a graph 
// 0-1
// 1-2
// 2-0

// so we have 3 vertices
// we can say each is root of itself

// [0 1 2]
//  0 1 2

// 1-take each edge and see parent of both
// 2-if not belong to same parent(root) 
// 3-union both and repeat

// lets take 0-1
// parent of 0=0&& parent of 1==1 ie. parent not equal so union->make parent of 0 parent of 1 or vice versa

// [0 0 2]
//  0 1 2 

//  now take 1-2
//  parent of 1==0 and parent of 2==2 ie. not equal so union-> make parent of 1 parent of 2 or vice versa

//  [0 0 0]
//   0 1 2

//   now take 2-0
//   parent of 0==0 and parennt of 2==0 ie. equal so we have a cycle;

#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
	int v;
	list<int> *adj;
	Graph(int v)
	{
		this->v=v;
		adj=new list<int>[v];

	}
	void add(int a,int b)
	{
		adj[a].push_back(b);
		
	}
};
int v=8;
int e;
vector<int> id(v);
int root(int a)
{
	while(id[a]!=a)
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
bool cycle(Graph gr)
{
	
	for(int i=0;i<v;i++)
	{
		id[i]=i;
	}

	for(int i=0;i<v;i++)	
	{
		int a=i;
		for(auto j=gr.adj[i].begin();j!=gr.adj[i].end();j++)
		{
			int b=*j;

			if(root(a)!=root(b))
			{
				union_(a,b);
			}
			else
				return 1;
		}


	}
	return 0;




}



int main()
{


	e=8;
	
	Graph gr(v);
	gr.add(0,2);
	gr.add(0,1);
	gr.add(0,3);
	gr.add(1,5);
	gr.add(5,6);
	gr.add(3,6);
	gr.add(2,4);
	gr.add(4,7);



	if(cycle(gr))
		cout<<"CYCLE DETECTED"<<endl;
	else
		cout<<"NO CYCLE"<<endl;

	



}