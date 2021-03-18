#include <bits/stdc++.h>


using namespace std;;

class Graph
{
	int v;
	list<int> *adj; 
	public:
	Graph(int v)
	{
		this->v=v;
		adj=new list<int>[v];
	}

	void add(int u,int v)
	{
		adj[u].push_back(v);
	}



	bool iscycle()
	{
		
		int count=0;

		queue<int> qu;

		vector<int> indegrees(v,0);

		for(int i=0;i<v;i++)
			for(auto c: adj[i])
				indegrees[c]++;

		for(int a:indegrees)
			cout<<a<<" ";


		// vector<int> in_degree(v, 0); 
  
  //   // Traverse adjacency lists to fill indegrees of 
  //   // vertices. This step takes O(V+E) time 
  //   for (int u = 0; u < v; u++) 
  //       for (auto v : adj[u]) 
  //           in_degree[v]++;

		for(int i=0;i<v;i++)
		{
			if(indegrees[i]==0)
			{
				qu.push(i);
			}
		}
		int P;

		while(!qu.empty())
		{
			
			P=qu.front();
			qu.pop();

			for(int a:adj[P])
			{
				indegrees[a]--;
				if(indegrees[a]==0)
				{
					qu.push(a);
				}
			}
			count++;

		}


		return(count!=v);






	}


};
int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("../../input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("../../output.txt", "w", stdout);
	#endif
	
	Graph gr(7);
	gr.add(0,1);
	gr.add(0,2);
	gr.add(0,3);

	gr.add(1,5);
	gr.add(2,5);
	gr.add(3,6);
	gr.add(5,4);
	gr.add(6,5);
	gr.add(4,1);
	
	
	if(gr.iscycle())
	{
		cout<<"CYCLIC"<<endl;
	}
	else
		cout<<"NON CYCLIC"<<endl;




}