#include <bits/stdc++.h>

using namespace std;
struct node{
    int u,v,wt;
    node(int x,int y,int w)
    {
        u=x;
        v=y;
        wt=w;
    }
};
bool comp(node a , node b)
{
    return (a.wt<b.wt);
}
int findPar(int a,vector<int>&parent)
{
    if(a==parent[a]) return a;
    return parent[a]=findPar(parent[a],parent);
}
void unionn(int a,int b,vector<int>&parent,vector<int>&rank)
{
    a=findPar(a,parent);
    b=findPar(b,parent);
    if(rank[a]<rank[b])
    parent[a]=b;
    else if(rank[a]>rank[b])
    parent[b]=a;
    else
    {
        parent[b]=a;
        rank[a]++;
    }
    return ;
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<node>adj;
    for(int i=0;i<e;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        adj.push_back(node(x,y,wt));
    }
    sort(adj.begin(),adj.end(),comp);
   vector<int>parent(v+1);
   vector<pair<int,int>>mst;
   vector<int>rank(v,0);
   for(int i=0;i<=v;i++)
   {
       parent[i]=i;
   }
   
   int c=0;
   for(auto it:adj)
   {
       if(findPar(it.u,parent)!=findPar(it.v,parent))
       {
           mst.push_back({it.u,it.v});
           c+=it.wt;
           unionn(it.u,it.v,parent,rank);
       }
   }
   cout<<c<<endl;
   for(auto i:mst)
   {
       cout<<i.first<<"-->"<<i.second<<endl;
   }
    return 0;
}
