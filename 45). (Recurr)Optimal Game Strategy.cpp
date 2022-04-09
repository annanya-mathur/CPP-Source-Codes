#include <iostream>

using namespace std;

int opStrategy (int arr[], int i, int j)
{
  if (i + 1 == j)
    return max (arr[i], arr[j]);
  return max(arr[i]+min(opStrategy(arr,i+1,j-1),
             opStrategy(arr,i+2,j)),
             arr[j]+min(opStrategy(arr,i,j-2),opStrategy(arr,i+1,j-1)));
}

int main ()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << opStrategy (arr, 0, n - 1);
  return 0;
}
