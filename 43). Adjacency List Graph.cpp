#include <iostream>
#include<vector>
using namespace std;

vector < vector < int >>res;

void printadjList (vector < int >adj[], int v)
{
  vector < vector < int >>r (v);
  for (int i = 0; i < v; i++)
    {
      r[i].push_back (i);
    for (auto & x:adj[i])
	{
	  r[i].push_back (x);

	}
    }
  res = r;
  return;
}

int main ()
{
  int v, e;
  cin >> v >> e;
  vector < int >adj[v];
  for (int i = 0; i < e; i++)
    {
      int p, q;
      cin >> p >> q;
      adj[p].push_back (q);
      adj[q].push_back (p);
    }
  printadjList (adj, v);

  for (int i = 0; i < v; i++)
    {
      for (int j = 0; j < res[i].size () - 1; j++)
	cout << res[i][j] << "->";
      cout << res[i][res[i].size () - 1];
      cout << endl;
    }

  return 0;
}
