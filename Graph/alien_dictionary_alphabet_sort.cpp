//Given a sorted dictionary of an alien language, find order of characters

// we firsf make graph for u->v in characters
// then we topologiacal sort it

#include<bits/stdc++.h>
using namespace std;


class Graph
{
	


public:
	int v;
	list <int> * adj;
	vector <char> ch;
	vector <int> have_parent;
	vector <int> visited;
	stack<int> st;

	
	Graph(int v)
	{
		this->v=v;
		adj=new list<int>[v];
		
		vector <int> have_parent1(v,0);
		have_parent=have_parent1;

		vector <int> visited1(v,0);
		visited=visited1;


	}
	void add(char u,char v)
	{

		adj[find(ch.begin(),ch.end(),u)-ch.begin()].push_back(find(ch.begin(),ch.end(),v)-ch.begin());
		have_parent[find(ch.begin(),ch.end(),v)-ch.begin()]=1;


	}
	void topological(int i)
	{
		for(auto j=adj[i].begin();j!=adj[i].end();j++)
		{
			if(visited[*j]!=1)
			{
				visited[*j]=1;
				topological(*j);
			}
		}
		st.push(i);
		return;
	}
	

};
vector<char> alien_dictionary(string words[],int n,int v)
	{
		string s,str;
		int m;

		Graph gr(v);


		for(int i=0;i<(n-1);i++)//building graph
		{
			s=words[i];
			str=words[i+1];
			m=min(s.length(),str.length());
			for(int j=0;j<m;j++)
			{
				if(s.at(j)!=str.at(j))
				{
					if(find(gr.ch.begin(),gr.ch.end(),s.at(j))==gr.ch.end())
					{

						gr.ch.push_back(s.at(j));
					}
					if(find(gr.ch.begin(),gr.ch.end(),str[j])==gr.ch.end())
					{
						gr.ch.push_back(str[j]);
					}
					gr.add(s[j],str[j]);
					break;
				}
			}

		}

		for(int i=0;i<v;i++)
		{
			

			if(gr.have_parent[i]==0)
			{
				gr.visited[i]=1;
				gr.topological(i);
			}
		}
		vector<char> final;

		while(!gr.st.empty())
		{
			final.push_back(gr.ch[gr.st.top()]);
			gr.st.pop();

			
		}
		return final;

	}
int main()
{
	string words[]={"caa", "aaa", "aab"};
	int n=3;//number of words
	int v=3;//number of letters in dictionary

	vector<char> final=alien_dictionary(words,n,v);
	for(char ch:final)
	{
		cout<<ch<<" ";
	}
	cout<<endl;

}