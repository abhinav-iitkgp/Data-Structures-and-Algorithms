#include <bits/stdc++.h>

using namespace std;
void printstack(stack<int> s)
{
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();

	}
	cout<<endl;

}

int main()
{
	stack <int> s;
	s.push(10);
	s.push(23);
	s.push(5);
	s.push(2);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(32);

	printstack(s);

	cout<<"s.size() "<<s.size()<<endl;
	cout<<"s.empty() "<<s.empty()<<endl;
	cout<<"s.top() "<<s.top()<<endl;
	s.pop();
	printstack(s);
	cout<<endl<<s.top()<<endl;




}