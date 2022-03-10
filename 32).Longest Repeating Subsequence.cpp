#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000][1000];
int longestRepeating(string s,string a,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]==a[j-1] && i!=j)
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][n];
}
int main()
{
   string s;
   cin>>s;
   string a=s;
   int n=s.size();
   cout<<longestRepeating(s,a,n)<<endl;
  cout<<"tabulation Table Formed"<<endl;
  for(int i=0;i<=n;i++)
  {
      for(int j=0;j<=n;j++)
      {
          cout<<dp[i][j]<<"\t";
      }
      cout<<endl;
  }
    return 0;
}
