
// This problem can be seen as shortest path in unweighted graph. Therefore we use BFS to solve this problem. We try all 8 possible positions 
// where a Knight can reach from its position. If reachable position is not already visited and is inside the board, we push 
// this state into queue with distance 1 more than its parent state. Finally we return distance of target position, when it gets pop out from queue.
//https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/
#include<bits/stdc++.h>

using namespace std;
struct box
{
	int x;
	int y;

};


int minStepToReachTarget(int knightPos[2],int targetPos[2],int n)
{
	int dx[8]={2,1,-2,-2,-1,-1,2,1};
	int dy[8]={1,2,1,-1,2,-2,-1,-2};

	box k,tar;
	k.x=knightPos[0];
	k.y=knightPos[1];
	tar.x=targetPos[0];
	tar.y=targetPos[1];

	bool visited[n+1][n+1];

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			visited[i][j]=false;
	}

	queue<box> qu;
	qu.push(k);
	visited[k.x][k.y]=true;

	
	box t,l;

	int dist[n+1][n+1];
	dist[k.x][k.y]=0;

	while(!qu.empty())
	{

		t=qu.front();
		qu.pop();

		for(int i=0;i<8;i++)
		{
			l.x=t.x+dx[i];
			l.y=t.y+dy[i];

			if(l.x==tar.x && l.y==tar.y)
			{

				return ++dist[t.x][t.y];
			}
			if(l.x>=1&&l.y<=n&&l.x<=n&&l.y>=1 && visited[l.x][l.y]==false)
			{
				qu.push(l);
				visited[l.x][l.y]=true;
				dist[l.x][l.y]=dist[t.x][t.y]+1;
			}
		}
	}



	return 0;
}


int main()
{
	int N = 30; 
    int knightPos[] = { 4, 5 }; 
    int targetPos[] = { 1, 1 }; 
    cout << minStepToReachTarget(knightPos, targetPos, N); 
    return 0; 
}