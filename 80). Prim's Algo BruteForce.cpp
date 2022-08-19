#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int key[n],parent[n]; bool mst[n];
   for(int i=0;i<n;i++)
   key[i]=INT_MAX;
    
    memset(parent,-1,sizeof(parent));
    memset(mst,false,sizeof(mst));
    key[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int minKey=INT_MAX ,index;
        for(int j=0;j<n;j++)
        {
            if(!mst[j] && minKey>key[j])
            {
                minKey=key[j] , index=j;
            }
        }
        // cout<<minKey<<endl;
        mst[index]=true;
        for(auto x:adj[index])
        {
           
            if(!mst[x.first] && key[x.first]>x.second)
            { parent[x.first]=index;
            key[x.first]=x.second;
            }
        }
        
    }
     
    for(auto i:parent)
    cout<<i<<" ";
    cout<<endl;
    return 0;
}
