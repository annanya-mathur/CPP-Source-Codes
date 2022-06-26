#include<bits/stdc++.h>

using namespace std;
typedef pair < int, pair < int, int >>pairs;

vector < vector < int >>threeSum (vector < int >&v)
{
  vector < vector < int >>res;
  set < pairs > st;
  int n = v.size ();
  for (int i = 0; i < n - 2; i++)
    {
      for (int j = i + 1; j < n - 1; j++)
	{
	  for (int k = j + 1; k < n; k++)
	    {
	      if (v[i] + v[j] + v[k] == 0)

		{
		  multiset < int >s;

		  s.insert (v[i]);
		  s.insert (v[j]);
		  s.insert (v[k]);
		  int a, b, c;
		  auto it = s.begin ();
		  a = *it;
		  it++;
		  b = *it;
		  it++;
		  c = *it;

		  pair y = make_pair (b, c);
		  pairs x = make_pair (a, y);
		  st.insert (x);
		}
	    }
	}
    }
for (auto i:st)
    {
      vector < int >temp;
      temp.push_back (i.first);
      temp.push_back (i.second.first);
      temp.push_back (i.second.second);
      res.push_back (temp);
    }
  return res;
}

int main ()
{
  int n;
  cin >> n;
  vector < int >v (n);
  vector < vector < int >>res;

  for (int j = 0; j < n; j++)
    {
      cin >> v[j];
    }

  res = threeSum (v);
for (auto i:res)
    {
    for (auto j:i)
	{
	  cout << j << " ";
	}
      cout << endl;
    }

  return 0;
}
