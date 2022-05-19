#include <iostream>
#include <vector>
using namespace std;

bool cycle (vector < int >adj[], int i, vector < int >&visited,
       vector < int >&dfsvis)
{
  visited[i] = 1;
  dfsvis[i] = 1;
for (auto x:adj[i])
    {
      if (!visited[x])
	{
	  if (cycle (adj, x, visited, dfsvis))
	    return true;
	}
      else if (dfsvis[x])
	return true;
    }
  dfsvis[i] = 0;
  return false;
}

int main ()
{
  int v, e;
  cin >> v >> e;
  vector < int >adj[v];
  int flag = 0;
  for (int i = 0; i < e; i++)
    {
      int x, y;
      cin >> x >> y;
      adj[x].push_back (y);
    }
  vector < int >visited (v, 0);
  vector < int >dfsvis (v, 0);
  for (int i = 0; i < e; i++)
    {
      if (!visited[i])
	{
	  if (cycle (adj, i, visited, dfsvis))
	    {
	      flag = 1;
	      cout << "Cycle is present" << endl;
	    }
	}
    }
  if (!flag)
    cout << "Cycle is not present" << endl;

  return 0;
}
