#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topoSort (vector < int >adj[], vector < int >&visited, stack < int >&st,
	  int i)
{
  visited[i] = 1;
for (auto x:adj[i])
    {
      if (!visited[x])
	{

	  topoSort (adj, visited, st, x);
	}
    }
  st.push (i);
}

int main ()
{
  int v, e;
  cin >> v >> e;
  vector < int >adj[v];
  for (int i = 0; i < e; i++)
    {
      int x, y;
      cin >> x >> y;
      adj[x].push_back (y);
    }
  vector < int >visited (v, 0);
  stack < int >st;
  for (int i = 0; i < v; i++)
    {
      if (!visited[i])
	{
	  topoSort (adj, visited, st, i);

	}
    }
  cout << "Topological Sort :";
  while (!st.empty ())
    {
      cout << st.top () << "\t";
      st.pop ();

    }
return 0;
}
