#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main ()
{
  int v, e;
  cin >> v >> e;
  vector < int >adj[v];
  vector < int >inDegree (v, 0);
   queue<int>q;
  for (int i = 0; i < e; i++)
    {
      int x, y;
      cin >> x >> y;
      adj[x].push_back (y);
    }

  for (int i = 0; i < v; i++)
    {
    for (auto x:adj[i])
	  {
	  inDegree[x]++;}
    }
    for(int i=0;i<v;i++)
    {
        if(inDegree[i]==0)
        q.push(i);
    }
    cout<<"TopoLogical Sort via BFS"<<endl;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        cout<<x<<"\t";
        for(auto j:adj[x])
        {
            inDegree[j]--;
            if(inDegree[j]==0)
            q.push(j);
        }
    }
   
 return 0;
}
