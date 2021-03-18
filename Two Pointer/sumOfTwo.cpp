#include <iostream>
#include<bits/stdc++.h>



using namespace std;

int main()
{
	// #ifndef JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif

	int n;
	cin>>n;
	int a[n];
	int x;
	cin>>x;

	for(int i=0;i<n;i++)
	{
		cin>>a[i];

	}
	
	sort(a,a+n);
	for(int i=0,j=n-1;i<j;)
	{
		int sum=a[i]+a[j];
		if(sum>x)
		{
			j--;
		}
		else if(sum<x)
		{
			i++;

		}
		else
		{
			cout<<"FOUND "<<a[i]<<" "<<a[j];
			return 0;

		}
	}
	cout<<"NOT FOUND";
}