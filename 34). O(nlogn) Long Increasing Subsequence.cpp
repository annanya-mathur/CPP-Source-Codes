#include <iostream>
#include <vector>
using namespace std;

vector < int >lis (1000);

int ceil_sequence (int r, int l, int x)
{
  while (r > l)
    {
      int m = l + (r - l) / 2;
      if (lis[m] >= x)
	r = m;
      else
	l = m + 1;
    }
  return r;
}

void longestIncSub (int arr[], int n)
{
  int len = 1;
  lis[0] = arr[0];
  for (int i = 1; i < n; i++)
    {
      if (arr[i] > lis[len - 1])
	{

	  lis[len] = arr[i];
	  len++;
	}
      else
	{
	  int c = ceil_sequence (len - 1, 0, arr[i]);
	  lis[c] = arr[i];
	}
    }
  cout << "LONGEST INCREASING SUBSEQUENCE" << endl;
  for (int i = 0; i < len; i++)
    {
      cout << lis[i] << "\t";
    }
  cout << endl;
  cout << "LENGTH OF LONGEST INCREASING SUBSEQUENCE" << "\t";
  cout << len;
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
  longestIncSub (arr, n);

  return 0;
}
