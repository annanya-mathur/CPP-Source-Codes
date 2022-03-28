#include <bits/stdc++.h>
using namespace std;

int minjumps (int dp[], int arr[], int n)
{
  for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
	{
	  if (j + arr[j] >= i)
	    {
	      if (dp[j] != INT_MAX)
		dp[i] = min (dp[i], dp[j] + 1);
	    }
	}
    }
  return dp[n - 1];

}

int main ()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int dp[n];
  dp[0] = 0;
  for (int i = 1; i < n; i++)
    dp[i] = INT_MAX;
  cout << minjumps (dp, arr, n) << endl;
  return 0;
}
