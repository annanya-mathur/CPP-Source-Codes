#include <bits/stdc++.h>
using namespace std;

int minJumps (int arr[], int n)
{
  if (n == 1)
    return 0;
  int res = INT_MAX;
  for (int i = 0; i < n - 1; i++)
    {
      if (i + arr[i] >= n - 1)
	{
	  int x = minJumps (arr, i + 1);
	  if (x != INT_MAX)
	    {
	      res = min (res, x + 1);
	    }
	}
    }
  return res;
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
  cout << "MINIMUM JUMPS TO REACH END" << "\t" << minJumps (arr, n) << endl;
  return 0;
}
