#include <iostream>
#include<vector>
using namespace std;

int main ()
{
  int v, e;
  cin >> v >> e;
  vector < pair < int, int >>adj[v];
  for (int i = 0; i < e; i++)
    {
      int u, v, wt;
      cin >> u >> v >> wt;
      adj[u].push_back ( {v, wt});
      adj[v].push_back ( {u, wt});
    }

  for (int i = 0; i < v; i++)
    {
    for (auto x:adj[i])
	cout << i << "->" << x.first << "\t" << "weight " << x.second << endl;
    }
  return 0;
}
