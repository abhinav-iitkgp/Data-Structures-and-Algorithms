#include<bits/stdc++.h>
using namespace std;


void dijkstra(int graph[9][9],int src,int dest)
{
	vector<int>dist(9,INT_MAX);
	vector<int> prev(9,0);

	dist[src]=0;

	vector<bool> spt(9,false);
	int p;
	prev[src]=src;
	vector<int>dup(9,INT_MAX);

	
	for(int j=0;j<9;j++)
	{
		p=min_element(dup.begin(),dup.end())-dup.begin();

		spt[p]=true;
		dup[p]=INT_MAX;


		for(int i=0;i<9;i++)
		{
			if(graph[p][i]!=0 && spt[i]==false && dist[i]>(dist[p]+graph[p][i]))
			{
				dist[i]=dist[p]+graph[p][i];
				dup[i]=dup[p]+graph[p][i];
				prev[i]=p;


			}
		}

		


	}

	cout<<"VERTEX \t\t Distance From "<<src<<endl;

	for(int i=0;i<9;i++)
	{
		cout<<i<<"\t \t"<<dist[i]<<endl;
	}
	string str;
	str=" "+to_string(dest)+" ";

	while(dest!=src)
	{
		dest=prev[dest];
		str=" "+to_string(dest)+str;

		
	}

	cout<<str<<endl;

	return;





}



int main()
{
	 int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0,5); 
  
    return 0; 
}