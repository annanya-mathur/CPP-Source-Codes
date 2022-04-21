#include <iostream>
using namespace std;

int optimalSt (int arr[], int i, int j, int n)
{
  int dp[n][n];
  for (int i = 0; i < n; i++)
    {
      dp[i][i + 1] = max (arr[i], arr[i + 1]);
    }
  for (int gap = 3; gap < n; gap++)
    {
      for (int i = 0; i < n; i++)
	{
	  int j = gap + i;
	  dp[i][j] =
	    max (arr[i] + min (dp[i + 2][j], dp[i + 1][j - 1]),
		 arr[j] + min (dp[i][j - 2], dp[i + 1][j - 1]));
	}
    }
  return dp[0][n - 1];
}

int main ()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
  cout << optimalSt (arr, 0, n - 1, n);
  return 0;
}
