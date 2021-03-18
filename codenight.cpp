#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class graph
{
    public:
    long long n;
    list<long long> *adj;
    vector<long long> val;
    graph(long long n)
    {
        this->n=n;
        adj=new list<long long>[n];
        vector<long long> v1(n,0);
        val=v1;
        
    }
    void add(long long u,long long v)
    {
        adj[u].push_back(v);
        
    }
    void add_val(long long u,long long x)
    {
        val[u]=x;
    }
    long long ma(long long v)
    {
        
        long long m=val[v];
        for(auto i=adj[v].begin();i!=adj[v].end();i++)
        {
            int u=ma(*i);
            if(u>m)
                m=u;
            
        }
        
        return m;
        
    }
    void add_x(long long u,long long x)
    {
        val[u]+=x;
        for(auto i=adj[u].begin();i!=adj[u].end();i++)
        {
            add_x(*i,x);
            
            
        }
        return;
    }
    long long get_val(long long x)
    {
        return val[x];
    }
    
};

int main() {
    #ifndef o
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    /* Enter your code here. Read input from STDIN. Prlong long output to STDOUT */
    long long n;
    cin>>n;
    graph gr(n+1);
    long long u,v;
    for(long long i=1;i<n;i++)
    {
        cin>>u>>v;
        gr.add(u,v);
    }
    for(long long i=0;i<n;i++)
    {
        cin>>v;
        gr.add_val(i+1,v);
    }
    long long t;
    cin>>t;
    char ch;
    long long x;
    for(long long i=0;i<t;i++)
    {
        cin>>ch;
        if(ch=='?')
        {
            cin>>v;
            cout<<gr.ma(v)<<endl;
        }
        else if(ch=='U')
        {
            cin>>v>>x;
            
            gr.add_x(v,x);
            
        }
        else if(ch=='G')
        {
            cin>>v;
            cout<<gr.get_val(v)<<endl;
        }
        else
            cout<<"-1"<<endl;
    }
    return 0;
}

