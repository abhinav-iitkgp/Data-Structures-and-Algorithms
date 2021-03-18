#include <bits/stdc++.h>

using namespace std;

class Graph
{

	int v;
	list<int> * adj;
	stack<int> st;

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
	bool rec(vector<int>visited)
	{
		if(st.empty())
			return false;
			int P=st.top();
			

			list<int>::iterator itr;
			for(itr=adj[P].begin();itr!=adj[P].end();itr++)
			{
				if(visited[*itr]==0)
				{
					
					visited[*itr]=-1;
					st.push(*itr);
					if(rec(visited))
						return true;
					else
					{
						visited[*itr]=-2;
						
					}

				}
				else if(visited[*itr]==-1)
				{
					return true;
				}	
				
			}
			visited[P]=-2;

			return false;

	}

	bool iscyclic()
	{
		//0===>WHITE
		//-1===>GREY
		//-2====>BLACK
		

		vector<int> visited(v,0);

		st.push(adj[0].front());
		visited[adj[0].front()]=-1;

		

		return rec(visited);




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
	// Graph gr(7);
	
	// gr.add(0,1);
	// gr.add(0,2);
	// gr.add(0,3);

	// // gr.add(1,5);
	// gr.add(2,5);
	// gr.add(3,6);
	// gr.add(5,4);
	// gr.add(6,5);
	// gr.add(4,1);


	Graph gr(6); 
    gr.add(0, 1); 
    gr.add(1, 2); 
    gr.add(2, 0); 
    gr.add(3, 4); 
    gr.add(4, 5);

	// Graph gr(7);
	// gr.add(0,1);
	// gr.add(0,2);
	// gr.add(0,3);
	// gr.add(2,4);
	// gr.add(3,5);
	// gr.add(4,1);
	// gr.add(5,4);
	// gr.add(5,6);
	// gr.add(4,6);


	if(gr.iscyclic())
		cout<<"CYCLIC";
	else
		cout<<"NON CYCLIC";
	cout<<endl;

}