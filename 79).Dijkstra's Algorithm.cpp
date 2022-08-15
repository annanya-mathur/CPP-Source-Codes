#include <bits/stdc++.h>

using namespace std;

int main()
{
   int e,v,src;
   cin>>e>>v>>src;
   vector<pair<int,int>>adj[v+1];
   
   for(int i=0;i<e;i++)
   {
       int x,y,z;
       cin>>x>>y>>z;
       adj[x].push_back({y,z});
   }
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   vector<int>dis(v+1,INT_MAX);
   pq.push({0,src});
   dis[src]=0;
   while(!pq.empty())
   {
       int s=pq.size();
       while(s--){
           auto x=pq.top().first;
           auto y=pq.top().second;
           pq.pop();
           for(auto i:adj[y])
           {
               int d=i.second+x;
               if(d<dis[i.first])
               {
                   dis[i.first]=d;
                   pq.push({d,i.first});
               }
           }
           
       }
   }
   for(auto i:dis)
   {
       cout<<i<<" ";
   }
    return 0;
}
