#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  int v, e;
  cin >> v >> e;
  vector < int >adj[v];
  vector < int >inDegree (v, 0);
  vector < int >OutDegree (v, 0);
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
	  inDegree[x]++;
	  OutDegree[i]++;
	}
    }

  cout << "Indegrees of Nodes" << endl;
  for (int i = 0; i < v; i++)
    {
      cout << inDegree[i] << "\t";
    }
  cout << endl;
  cout << "Outdegrees of Nodes" << endl;
  for (int i = 0; i < v; i++)
    {
      cout << OutDegree[i] << "\t";
    }
  return 0;
}
