#include <iostream>
#include <vector>
using namespace std;

bool BipartiteDfs(vector<int>adj[],vector<int>&color,int i,int l)
{
   
   color[i]=l;
    l=!l;
    for(auto x:adj[i])
    {
        if(color[x]==-1)
        {
            if(!BipartiteDfs(adj,color,x,l))
            return false;
        }
        else
        if(color[i]==color[x])
        return false;
    }
    return true;
}
int main()
{
    int v,e;
    cin>>v>>e;
    
    vector<int>adj[v];
    vector<int>color(v,-1);
    int flag=0,l=0;
    for(int i=0;i<e;i++)
    {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0;i<v;i++)
    {
        if(color[i]==-1)
        {
            if(!BipartiteDfs(adj,color,i,l))
            {
                flag=1;
                cout<<"Graph is not Bipartite"<<endl;
                break;
            }
        }
    }
    if(!flag)
    cout<<"Graph is Bipartite"<<endl;
    return 0;
}
