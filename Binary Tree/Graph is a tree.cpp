#include<bits/stdc++.h>

using namespace std;

class Graph
{
	list<int> *adj;
	int v;

public:
	Graph(int v)
	{
		this->v=v;
		adj=new list<int>[v];


	}
	void addEdge(int u,int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool notcycle(int i,int p,vector<int> &visited)
	{
		if(visited[i]==1)
			return false;
		visited[i]=1;

		for(auto j=adj[i].begin();j!=adj[i].end();j++)
		{
			
			if(*j!=p&&!notcycle(*j,i,visited))
				return false;
		}
		return true;


	}
	bool isTree()
	{
		bool flag=false;
		vector<int> visited(v,0);

		flag=notcycle(0,0,visited);
		for(int i=0;i<visited.size();i++)
		{
			if(visited[i]==0)
				flag=false;
		}
		return flag;
		//no cycle
		//all connected
	}

};

int main() 
{ 

    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.isTree()? cout << "Graph is Tree\n": 
                 cout << "Graph is not Tree\n"; 
  
    Graph g2(5); 
    g2.addEdge(1, 0); 
    g2.addEdge(0, 2); 
    g2.addEdge(2, 1); 
    g2.addEdge(0, 3); 
    g2.addEdge(3, 4); 
    g2.isTree()? cout << "Graph is Tree\n": 
                 cout << "Graph is not Tree\n"; 
  
    return 0; 
}