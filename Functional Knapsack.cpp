#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool compare (pair < int, int >p1, pair < int, int >p2)
{
  double v1 = (double) p1.first / p1.second;
  double v2 = (double) p2.first / p2.second;
  return v1 > v2;

}

int main ()
{
  int n, w;
  cin >> n;
  cin >> w;
  vector < pair < int, int >>v (n);
  for (int i = 0; i < n; i++)
    {
      cin >> v[i].first;
      cin >> v[i].second;
    }
  sort (v.begin (), v.end (), compare);

  // for(int i=0;i<n;i++)
  // {
  //     cout<<v[i].first<<"\t";
  //     cout<<v[i].second<<"\n";
  // }
  int res = 0;
  for (int i = 0; i < n; i++)
    {
      if (v[i].second <= w)
	{
	  res += v[i].first;

	  w -= v[i].second;

	}
      else
	{
	  if (w != 0)
	    {

	      int y = v[i].first / v[i].second;

	      res += w * y;
	    }
	  w = 0;
	  break;
	}
    }
  cout << res;
  return 0;
}
