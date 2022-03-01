#include <iostream>
using namespace std;

int fib (int n)
{
  int tabulation[n+1];
  tabulation[0]=0;
  tabulation[1]=1;
  for(int i=2;i<=n;i++)
  {
      tabulation[i]=tabulation[i-1]+tabulation[i-2];
  }
  
  return tabulation[n];
}

int main ()
{
  int n;
  cin >> n;
  
  cout<<fib(n)<<endl;
  return 0;

}
