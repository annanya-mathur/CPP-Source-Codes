#include <bits/stdc++.h>

using namespace std;
 bool cycleBfs(vector <int> adj[],int i, vector<int>&visited){
        queue<pair<int,int>>q;
        q.push({i,-1});
        visited[i]=1;
        while(!q.empty())
        {
            int s=q.size();
            while(s--){
                auto x=q.front();
                q.pop();
                for(auto j:adj[x.first]){
                if(!visited[j])
                { visited[j]=1;
                    q.push({j,x.first});
                }
                else if(x.second!=j)
                return true;
                
                }
            }
        }
        return false;
    }
int main()
{
    int v,e,f=0;
    cin>>v>>e;
    vector<int>adj[e];
    for(int i=0;i<v;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
   vector<int>visited(v,0);
   for(int i=0;i<v;i++)
   {
       if(!visited[i])
       {
           if(cycleBfs(adj,i,visited)) {f=1 ;break; }
       }
   }
   if(f) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
    return 0;
}
