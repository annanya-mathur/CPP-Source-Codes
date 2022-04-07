#include <iostream>
using namespace std;

int editDis (string s, string t)
{
  int n = s.size (), m = t.size ();
  int dp[n + 1][m + 1];
  for (int i = 0; i < n; i++)
    dp[i][0] = i;
  for (int i = 0; i < m; i++)
    dp[0][i] = i;
  for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
	{

	  if (s[i - 1] == t[j - 1])
	    dp[i][j] = dp[i - 1][j - 1];
	  else
	    dp[i][j] =
	      1 + min (dp[i - 1][j], min (dp[i - 1][j - 1], dp[i][j - 1]));
	}
    }
  return dp[n][m];
}

int main ()
{
  string s, t;
  cin >> s >> t;
  cout << editDis (s, t);

  return 0;
}
