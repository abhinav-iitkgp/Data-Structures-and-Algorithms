#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int u)
{
	int largest=u;
	int l=2*u +1;
	int r=2*u +2;
	if(l<n && arr[l]>arr[largest])
		largest=l;
	if(r<n && arr[r]>arr[largest])
		largest=r;
	if(largest!=u)
	{
		swap(arr[u],arr[largest]);
		heapify(arr,n,largest);
	}
}
void heapSort(int arr[],int n)
{
	int lasti=(n/2)-1;
	for(int i=lasti;i>=0;i--)
	{
		heapify(arr,n,i);
	}

	for(int i=n-1;i>0;i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}
int main()
{
	int arr[]={932 ,66 ,777 ,426, 127, 404, 63 ,281 ,426 ,317, 735, 628 ,543, 78, 31 ,811 ,626, 104, 389 ,412, 687 ,296, 35, 252 ,441, 675 ,604};

	int n=sizeof(arr)/sizeof(arr[0]);

	heapSort(arr,n);

	for(int i: arr)
		cout<<i<<" ";

}