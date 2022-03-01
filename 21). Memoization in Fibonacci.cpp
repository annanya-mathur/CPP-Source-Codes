#include <iostream>
using namespace std;

int memo[10000];
void fib (int n)
{
  if (memo[n] == -1)
    {
      int r = 0;
      if (n == 0 || n == 1)
	r = n;
      else
	{

	  fib (n - 1);
	  fib (n - 2);
	  r = memo[n - 1] + memo[n - 2];
	}
      memo[n] = r;

    }

  return;

}

int main ()
{
  int n;
  cin >> n;

  for (int i = 0; i <= n; i++)
    memo[i] = -1;

  fib (n);
  cout << memo[n] << endl;

  return 0;
}
