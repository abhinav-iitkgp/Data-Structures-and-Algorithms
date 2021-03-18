#include <bits/stdc++.h>

using namespace std;


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
void locate(vector <int> *v,vector<int> *A,int N,int M,int i,int j)
{
    int dx[]={0,0,1,-1,1,-1,1,-1};
    int dy[]={1,-1,0,0,1,-1,-1,1};
    v[i][j]=1;
    
    int px,py,c=0;
    for(int t=0;t<8;t++)
    {
        px=i+dx[t];
        py=j+dy[t];
        
        if(px>=0 && px<N && py>=0 && py<M && v[px][py]==0 && (A[px][py]==1))
        {

            locate(v,A,N,M,px,py);
        }
    }
    A[i][j]=0;
    return;
}

int findIslands(vector<int> A[], int N, int M) {
    vector<int> v[N];

    
    for(int i=0;i<N;i++)
    {
        vector <int> temp(M,0);
        v[i]=temp;
        
    }
    int c=0;
    
    for(int i=0;i<N;i++)
    {
        // print(A,N);

        
        
        
        for(int j=0;j<M  ;j++)
        {
            if(A[i][j]==1){
            
            c++;
            locate(v,A,N,M,i,j);
            }   
        }
    }
    return c;

    // Your code here
}

int main()
{   
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("../input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("../output.txt", "w", stdout);
    #endif
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;

        vector<int> A[n];

        for(int i=0;i<n;i++)
        {
            vector<int> temp(m);
            A[i]=temp;

            for(int j=0;j<m;j++)
            {
    


                cin>>A[i][j];
    

            }
        }

        cout<<findIslands(A,n,m)<<endl;
    }
}