#include<bits/stdc++.h>
using namespace std;

int main()
{
    int e,v;
    cin>>e>>v;
    vector<pair<int,int>>adj[v];
    for(int i=0;i<e;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    vector<bool>mst(v,false);
    vector<int>parent(v,-1);
    vector<int>key(v);
    for(int i=0;i<v;i++){
         
         key[i]=INT_MAX;
    }
    key[0]=0;
    for(int i=0;i<v-1;i++)
    {
        
        int y=pq.top().second;
        pq.pop();
        mst[y]=true;
        for(auto x:adj[y])
        {
            if(!mst[x.first] && x.second<key[x.first])
            {
                parent[x.first]=y;
                pq.push({x.second,x.first});
                key[x.first]=x.second;
            }
        }
        
        
    }
    for(auto i:key)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:parent)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}
