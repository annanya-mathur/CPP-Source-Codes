#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool bfscycle (vector < int >adj[], vector < int >visited, int v, int i)
{
  vector < int >parent (v, -1);

  queue < int >q;
  visited[i] = 1;
  q.push (i);
  while (!q.empty ())
    {
      int x = q.front ();
      q.pop ();

    for (auto j:adj[x])
	{
	  if (!visited[j])
	    {
	      visited[j] = 1;
	      parent[j] = x;
	      q.push (j);
	    }
	  else if (parent[x] != j)
	    return true;
	}

    }
  return false;
}

int main ()
{
  int v, e;
  cin >> v >> e;
  vector < int >adj[v];
  vector < int >visited (v, 0);
  int flag = 0;
  for (int i = 0; i < e; i++)
    {
      int x, y;
      cin >> x >> y;
      adj[x].push_back (y);
      adj[y].push_back (x);
    }
  for (int i = 0; i < v; i++)
    {
      if (!visited[i])
	{
	  if (bfscycle (adj, visited, v, i))
	    flag = 1;
	}
    }
  if (flag)
    cout << "Cycle is present" << endl;
  else
    cout << "Cycle is not present" << endl;
  return 0;
}
