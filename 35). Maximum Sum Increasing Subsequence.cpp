#include <iostream>
#include<vector>

using namespace std;
vector < int >dp;

int MaxIncSumSeq (int arr[], int n)
{
  for (int i = 1; i < n; i++)
    {
      dp.push_back (arr[i]);
      for (int j = 0; j < i; j++)
	{
	  if (arr[j] < arr[i])
	    {
	      dp[i] = max (dp[i], arr[i] + dp[j]);

	    }
	}
    }
  int res = dp[0];
  cout<<"DP"<<"\t"<<dp[0]<<"\t";
  for (int i = 1; i < n; i++)
    {
      cout << dp[i] << "\t";
      res = max (res, dp[i]);
    }
  cout << endl;
  return res;

}

int main ()
{
  int n;
  cin >> n;
  int arr[n];
  cout<<"INPUT"<<"\t";
  for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      cout<<arr[i]<<"\t";
    }
    cout<<endl;
  dp.push_back (arr[0]);
  int x = MaxIncSumSeq (arr, n);
  cout << "MAXIMUM INCREASING SUM SUBSEQUENCE" << "\t" << x;
  return 0;
}
