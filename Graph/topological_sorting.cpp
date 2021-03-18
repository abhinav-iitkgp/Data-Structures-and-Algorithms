

//here we if u is ansenstor of v (u->v) then in topological sort u comes before v
//here we use dfs to store elements in stack during dfs and finally print the 
//from top to bottom


#include<bits/stdc++.h>

using namespace std;
class graph
{
	

public:
	int n;
	list<int> *adj;
	stack<int> st;
	vector<bool> visited1;
	vector<int> parent;
	graph(int n)
	{
		this->n=n;
		adj=new list<int>[n];
		
		vector<bool> visited(n,false);
		visited1=visited;

		vector<int> parent1(n,0);
		parent=parent1;


		
		

	}
	void add(int u,int v)
	{
		adj[u].push_back(v);
		parent[v]=1;
	}
	void topologiacal(int src)
	{	
		
		for(auto i=adj[src].begin();i!=adj[src].end();i++)

		{
			if(visited1[*i]==false)
			{
				visited1[*i]=true;
				topologiacal(*i);

			}
			
		}

		st.push(src);
		return ;

		


		




	}
	void print_stack()
	{
		while(!st.empty())
		{
			cout<<st.top()<<" ";
			st.pop();
		}
		cout<<endl;
	}


};






int main()
{
	
	int n,u,v;
	n=10;

	graph gr(n);


	gr.add(0,1);
	gr.add(0,2);
	gr.add(0,3);
	gr.add(1,5);
	gr.add(1,4);
	gr.add(4,5);
	gr.add(2,5);
	gr.add(3,6);
	gr.add(6,5);
	gr.add(3,7);
	gr.add(8,3);
	gr.add(8,9);

	for(int i=0;i<n;i++)
	{
		if(gr.parent[i]==0)
		{
			gr.visited1[i]=true;
			gr.topologiacal(i);
		}
	}

	gr.print_stack();


	
	
	
}