#include <iostream>
#include <vector>

using namespace std;

int
main ()
{

  int n;
  cin >> n;
  vector < int >v;
  for (int i = 0; i < n; i++)
    {
      int q;
      cin >> q;
      v.push_back (q);
    }

  vector < int >min_array (n);

  vector < int >max_array (n);

  min_array[0] = v[0];

  max_array[n - 1] = v[n - 1];
  

  for (int i = 1; i < n; i++)
    {
      min_array[i] = min (min_array[i - 1], v[i]);
    }
  for (int i = n - 2; i >= 0; i--)
    {
      max_array[i] = max (max_array[i + 1], v[i]);

    }
  int i = 0, j = 0, result = 0;
  while (i < n && j < n)
    {
      if (min_array[i] <= max_array[j])
	{
	  result = max (result, j - i);
	  j++;
	}
      else
	i++;
    }
  cout << result << endl;


  return 0;
}
