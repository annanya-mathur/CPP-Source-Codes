#include <iostream>
#include <queue>
using namespace std;

int main ()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
  priority_queue < int, vector < int >, greater < int >> minheap;
  for (int i = 0; i < n; i++)
    {
      minheap.push (arr[i]);
    }
  int x = 0, y = 0, ans = 0;
  while (minheap.empty () == false)
    {
      x = minheap.top ();
      minheap.pop ();

      if (minheap.empty () == false)
	{
	  y = minheap.top ();
	  minheap.pop ();
	  x += y;
	  ans += x;
	  minheap.push (x);
	}

    }
  cout << ans << endl;
  return 0;
}
