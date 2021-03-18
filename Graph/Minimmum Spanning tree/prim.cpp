#include <bits/stdc++.h>
using namespace std;
#define v 5

void primMST(int graph[v][v])
{
	vector<int> prim(v,-1);
	vector<int> visited(v,0);

	prim[0]=1;
	visited[0]=1;
	int min,min_c,min_j;

	for(int i=0;i<v-1;i++)
	{

		min=9999;
		for(int j=0;j<v;j++)

		{
			if(prim[j]!=-1)
			{
			for(int c=0;c<v;c++)
			{
				if(graph[j][c]!=0&&visited[c]!=1&&graph[j][c]<min)
				{
					min=graph[j][c];
					min_j=j;
					min_c=c;
				}
			}
			}
		}
		cout<<min_j<<" "<<min_c<<" \t"<<graph[min_j][min_c]<<endl;
		visited[min_c]=1;
		prim[min_c]=1;



	}

}
int main()
{
	/* Let us create the following graph 
        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | / \ | 
    (3)-------(4) 
            9     */



    int graph[v][v] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
 
    // Print the solution 
    primMST(graph); 
 
    return 0;
}