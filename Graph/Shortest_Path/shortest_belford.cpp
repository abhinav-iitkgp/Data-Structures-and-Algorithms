#include<bits/stdc++.h>

using namespace std;


class Graph
{
	int v;
	list<int>* adj;

	

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

	void perform_shortest(int source,int dest)
	{
		vector<int> dist(v,0);
		vector<int> prev(v,source);
		vector<int> visited(v,0);
		dist[source]=0;

		queue<int> qu;
		visited[source]=-1;
		qu.push(source);
		int c=0;//for distance

		while(!qu.empty())
		{

			int p=qu.front();
			qu.pop();

			list<int> :: iterator itr;

			for(itr=adj[p].begin();itr!=adj[p].end();itr++)
			{
				if(visited[*itr]==0)
				{
					visited[*itr]=-1;
					qu.push(*itr);
					prev[*itr]=p;
					dist[*itr]=dist[p]+1;
				}
				if(*itr==dest)
					goto label;

			}

		}
		label:

		cout<<"Shortest distance from "<<source<<" is "<<dist[dest]<<endl;
		cout<<"Path ";
		vector <int> path;

		int d=dest;

		while(d!=source)
		{
			path.push_back(d);
			d=prev[d];
		}
		path.push_back(source);

		for(int i=path.size()-1;i>=0;i--)
		{
			cout<<path[i]<<" ";
		}
		cout<<endl;


		



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
	Graph gr(10);
	gr.add( 0, 1); 
    gr.add( 0, 3); 
    gr.add( 1, 2); 
    gr.add( 3, 4); 
    gr.add( 3, 7); 
    gr.add( 4, 5); 
    gr.add( 4, 6); 
    gr.add( 4, 7); 
    gr.add( 5, 6); 
    gr.add( 6, 7); 
    gr.perform_shortest(0,7);

}