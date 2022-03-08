#include <iostream>
using namespace std;
int coin_change (int coin[], int n, int sum)
{
  if (sum == 0)
    return 1;
  if (n <= 0)
    return 0;
  int res = coin_change (coin, n - 1, sum);
  if (coin[n - 1] <= sum)
    {
      res += coin_change (coin, n, sum - coin[n - 1]);
    }
  return res;
}

int main ()
{
  int n, sum;
  cin >> n;
  int coin[n];
  for (int i = 0; i < n; i++)
    {
      cin >> coin[i];
    }
  cin >> sum;
  cout << coin_change (coin, n, sum);
  return 0;
}
