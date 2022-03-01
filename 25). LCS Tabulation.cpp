#include <iostream>
using namespace std;

int dp[10000][10000];
int tabulation (string s1, string s2, int n, int m)
{
  for (int i = 1; i <= n; i++)
    {
      for (int j = 0; j <= m; j++)
	{
	  if (s1[i - 1] == s2[j - 1])
	    dp[i][j] = 1 + dp[i - 1][j - 1];
	  else
	    dp[i][j] = max (dp[i][j - 1], dp[i - 1][j]);
	}
    }
  return dp[n][m];
}

int main ()
{
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size (), m = s2.size ();
  cout << "LONGEST COMMON SUBSEQUENCE:" << "\t" << tabulation (s1, s2, n,m) << endl;
  
  cout << "MATRIX FORMED" << endl;
  for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= m; j++)
	{
	  cout << dp[i][j] << "\t";
	}
      cout << endl;
    }
  return 0;
}
