// /* A recursive utility function to solve N 
//    Queen problem */
// bool solveNQUtil(int board[N][N], int col) 
// { 
//     /* base case: If all queens are placed 
//       then return true */
//     if (col >= N) 
//         return true; 
  
//     /* Consider this column and try placing 
//        this queen in all rows one by one */
//     for (int i = 0; i < N; i++) { 
//         /* Check if the queen can be placed on 
//           board[i][col] */
//         if (isSafe(board, i, col)) { 
//              Place this queen in board[i][col] 
//             board[i][col] = 1; 
  
//             /* recur to place rest of the queens */
//             if (solveNQUtil(board, col + 1)) 
//                 return true; 
  
//             /* If placing queen in board[i][col] 
//                doesn't lead to a solution, then 
//                remove queen from board[i][col] */
//             board[i][col] = 0; // BACKTRACK 
//         } 
//     } 
  
//     /* If the queen cannot be placed in any row in 
//         this colum col  then return false */
//     return false; 
// } 



#include <bits/stdc++.h>
using namespace std;
int done;
void print(vector<int> f)
{
    done=1;
    cout<<"[";
    for(auto i=f.begin();i!=f.end();i++)
    {
        cout<<((*i)+1)<<" ";
        *i=0;
        
    }
    cout<<"] ";
    return;
    
}
bool isvalid(vector<int > f,int i,int c)
{
    for(int j=0;j<c;j++)
    {
        int p=f[j];
        if(p==i||i==(p+(c-j))||i==(p-(c-j)))
        return false;
    }
    return true;
     
    
}
void place_queen(vector<vector<int>> chess,int n,vector<int> f,int c)
{
    //start with left column top box (0->n-1)
    //for each box in that colum recusively call the function to next column 
    // if it is valid to put it there
        //put queen there
        
        //if we have put in last column
            //print 
            //reinitialise f and chess
            //start with next position in first column
    //else try other boxes in the same column
    //if reach end of colomn return to previous column
    
    
    
    
    
    for(int i=0;i<n;i++)
    {
        if(isvalid(f,i,c))
        {
         
            chess[i][c]=1;
            f[c]=i;
            

            
            if(c==(n-1))
            {
                int t=0;
                for(int l:f)
                {
                    chess[l][t]=0;
                    t++;
                }
                
                print(f);
                
                return ;
                
            }
            else
            {
                place_queen(chess,n,f,c+1);
                
                    
                chess[i][c]=0;
                f[c]=0;
                
            }
        }
        
        
        
    }
    
    return ;
}

int main() {
    #ifndef o
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
	int t;
	
	cin>>t;
	while(t--)
	{
	    done=0;
	    int n;
	    cin>>n;
	    vector<vector<int>> chess(n,vector<int>(n,0));
	    vector<int> f(n,0);
	    place_queen(chess,n,f,0);
	    if(done!=1)
	    cout<<"-1";
	    cout<<endl;
	    
	    
	}
	return 0;
}