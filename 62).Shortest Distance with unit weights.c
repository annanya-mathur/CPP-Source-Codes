#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int shortBfs (vector < int >adj[], int v, int t, int d)
{
  queue < int >q;
  q.push (t);
  vector < int >dis (v, 10000000);
  dis[t] = 0;
  while (!q.empty ())
    {
      int x = q.front ();
      q.pop ();
    for (auto i:adj[x])
	{
	  int y = dis[x] + 1;
	  if (y < dis[i])
	    {
	      q.push (i);
	      dis[i] = y;
	    }
	}
    }
    cout<<"Distance Array"<<"\t";
for (auto i:dis)
    cout << i << "\t";
  cout << endl;
  return dis[d];
}

int main ()
{
  int e, v;
  cin >> e >> v;
  vector < int >adj[v];
  for (int i = 0; i < e; i++)
    {
      int x, y;
      cin >> x >> y;
      adj[x].push_back (y);
      adj[y].push_back (x);
    }
    
  cout << shortBfs (adj, v, 0, 6);
  return 0;
}

   
