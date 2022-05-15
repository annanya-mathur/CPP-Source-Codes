#include <iostream>
#include <vector>
using namespace std;

void dfs (int i, vector < int >&visited, vector < int >adj[], vector < int >&res)
{
  visited[i] = 1;
  res.push_back (i);
for (auto x:adj[i])
    {				
      if (!visited[x])
	dfs (x, visited, adj, res);
    }
  return;
}

void traverse (vector < int >adj[], int v)
{
  vector < int >visited (v + 1, 0);
  vector < int >res;
  for (int i = 1; i <= v; i++)
    {
      if (!visited[i])

	{
	  dfs (i, visited, adj, res);
	}
    }
  cout << "Depth First Search Traversal" << endl;

for (auto i:res)
    cout << i << "\t";
  return;
}

int main ()
{
  int e, v;
  cin >> e >> v;
  vector < int >adj[v + 1];
  for (int i = 0; i < e; i++)
    {
      int x, y;
      cin >> x >> y;

      adj[x].push_back (y);
      adj[y].push_back (x);
    }

  traverse (adj, v);
  return 0;
}
