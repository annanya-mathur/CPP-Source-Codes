#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int u,v,w;
    Node (int x,int y,int z)
    {
        u=x;
        v=y;
        w=z;
    }
    
};
bool detectNCycle(vector<Node>ed)
{
    int n=ed.size();
    vector<int>dis(n,INT_MAX);
    dis[0]=0;
    for(int i=0;i<n-1;i++)
    {
        for(auto &it:ed)
        {
            if(dis[it.v]>dis[it.u]+it.w)
            dis[it.v]=dis[it.u]+it.w;
        }
    }
    for(auto &it:ed)
    {
        if(dis[it.v]>dis[it.u]+it.w)
        return 1;
    }
    return 0;
}
int main()
{
   int n;
   cin>>n;
   vector<Node>ed;
   for(int i=0;i<n;i++)
   {
       int x,y,z;
       cin>>x>>y>>z;
       ed.push_back( Node(x,y,z));
   }
   if(detectNCycle(ed))
   cout<<"Negative Cycle Exists"<<endl;
   else
   cout<<"Negative Cycle Doesn't Exists"<<endl;

    return 0;
}
