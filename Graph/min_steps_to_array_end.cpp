//https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/


// taking start;
// count++//for number of jump
// iterate throught all its adjacent(not visited earlier)--store max leap  i that can b made by any i and also store its index in max_leap_i
// replace start with max_leap_i


#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[],int n)
{
	int start=0,c=0;
	int max_leap,max_leap_i;
	int t=0;
	while(1)
	{
		
		c++;
		max_leap=0;
		max_leap_i=start+1;

		if(start+arr[start]>=(n-1))
			return c;

		for(int i=t+1;i<=start+arr[start];i++)
		{
			if((arr[i]+i-arr[start])>max_leap)
			{
				max_leap=arr[i]+i-arr[start];
				max_leap_i=i;
			}
		}
		t=start+arr[start];//so that se iterate in next new numbers

		start=max_leap_i;

	}
	return 0;
}

int main()
{
	// int arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ;
	int arr[] = { 2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
	// int arr[] = { 1, 3, 6, 1, 0, 9 };
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Minimum number of jumps to"; 
    cout << " reach the end is " << minJumps(arr, n)<<endl; 
    return 0; 
}