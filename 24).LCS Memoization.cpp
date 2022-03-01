#include <iostream>
#include <algorithm>

using namespace std;

string sub = "";
int memo[1000][1000];

int memo_lcs (string s1, string s2, int n, int m)
{

  if (memo[n][m] == -1)
    {
      if (n == 0 || m == 0)
	{
	  memo[n][m] = 0;

	}
      else
	{
	  if (s1[n - 1] == s2[m - 1])
	    {
	      sub += s1[n - 1];
	      memo[n][m] = 1 + memo_lcs (s1, s2, n - 1, m - 1);
	    }
	  else
	    {
	      memo[n][m] =
		max (memo_lcs (s1, s2, n - 1, m),
		     memo_lcs (s1, s2, n, m - 1));
	    }

	}
    }
  return memo[n][m];
}

int main ()
{
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size (), m = s2.size ();
  for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= m; j++)
	memo[i][j] = -1;
    }

  cout << "LONGEST COMMOM SUBSEQUENCE\t";
  int x = memo_lcs (s1, s2, s1.size (), s2.size ());
  reverse(sub.begin(),sub.end());	
  cout << sub << "\n" << "WITH LENGTH" << "\t" << x << endl;

  return 0;
}
