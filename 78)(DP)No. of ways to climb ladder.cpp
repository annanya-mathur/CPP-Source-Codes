#include <bits/stdc++.h>
int memo[100001];
void wayesLadder(int n)
{   
    if(memo[n]!=-1 || n<0)
    return;
    
    if(n==1 || n==0) {memo[n]= 1; return;}
    wayesLadder(n-1);
    wayesLadder(n-2);
    wayesLadder(n-3);
    memo[n]=memo[n-1]+memo[n-2]+memo[n-3];
    
}
using namespace std;

int main()
{
   int n;
   cin>>n;
   memset(memo,-1,sizeof(memo));
   wayesLadder(n);
   cout<<memo[n]<<endl;

    return 0;
}
