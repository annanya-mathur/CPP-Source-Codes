#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs (vector < int >&visited, vector < int >adj[], int i)
{
  stack < int >st;
  st.push (i);
  while (!st.empty ())
    {
      int x = st.top ();
      st.pop ();

      if (!visited[x])
	{
	  cout << x << "\t";
	  visited[x] = true;
	}

    for (auto j:adj[x])
	{
	  if (!visited[j])
	    st.push (j);
	}
    }
  return;
}

int main ()
{
  int v, e;
  cin >> v >> e;
  vector < int >adj[v];
  vector < int >visited (v, 0);

  for (int i = 0; i < e; i++)
    {
      int x, y;
      cin >> x >> y;
      adj[x].push_back (y);
    }

  for (int i = 0; i < v; i++)
    {
      if (!visited[i])
	{
	  dfs (visited, adj, i);
	}
    }

  return 0;
}
