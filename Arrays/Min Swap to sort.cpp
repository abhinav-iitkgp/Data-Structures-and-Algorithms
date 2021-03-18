

//we count the number of points in the cycle
//min_swap=min_swap+(cy_len-1) for all the cycles
//ans = Σi = 1k(cycle_size – 1)
//where k is the number of cycles


#include<bits/stdc++.h>
using namespace std;




int minSwaps(int arr[], int N){
    
    pair<int,int> p[N];
    int visited[N];
    for(int i=0;i<N;i++)
    {
        p[i].first=arr[i];
        p[i].second=i;
        visited[i]=0;
    }

    sort(p,p+N);
    int min_swap=0;


    for(int i=0;i<N;i++)
    {
        if(p[i].second!=i&&visited[i]==0) 
        {
            int c=i;
            int cy_len=0;
            while(visited[c]!=1)
            {
                visited[c]=1;
                cy_len++;

                c=p[c].second;


            }
            min_swap=min_swap+(cy_len-1);
        }

    }
    return min_swap;
    /*Your code here */
}
int main()
{
    int arr[]={1,6,8,7};
    cout<<minSwaps(arr,4);
}