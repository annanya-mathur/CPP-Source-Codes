#include <iostream>
#include <climits>
using namespace std;

int chainMulti (int arr[], int i, int j)
{
  if (i + 1 == j)
    return 0;
  int res = INT_MAX;
  for (int k = i + 1; k < j; k++)
    {
      res =
	min (res, chainMulti (arr, i, k) + chainMulti (arr, k,j) +
	     (arr[i] * arr[k] * arr[j]));
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
  cout << chainMulti (arr, 0, n - 1);
  return 0;
}
