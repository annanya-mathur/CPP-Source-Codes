#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int arr[10000], tree[40000];

void segmentTree (int start, int end, int index)
{
  if (start == end)
    {
      tree[index] = arr[start];
      return;
    }

  int mid = (start + end) / 2;
  segmentTree (start, mid, 2 * index + 1);
  segmentTree (mid + 1, end, 2 * index + 2);
  tree[index] = max (tree[2 * index + 1], tree[2 * index + 2]);

}

int search_max (int start, int end, int l, int r, int index)
{
  if (r < start || l > end)
    return INT_MIN;
  if (l <= start && r >= end)
    return tree[index];
  int mid = (start + end) / 2;
  return max (search_max (start, mid, l, r, 2 * index + 1),
	      search_max (mid + 1, end, l, r, 2 * index + 2));
}

int main ()
{
  int n, l, r;
  cin >> n;
  for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
  int x = (int) ceil ((log2 (n)));
  int size = (2 * (int) pow (2, x)) - 1;
  segmentTree (0, n - 1, 0);
  cout << "SEGMENT TREE FORMED: " << endl;
  for (int i = 0; i < size; i++)
    {
      cout << tree[i] << "\t";
    }
  cin >> l >> r;
  cout << endl;
  cout << "Maximum between: " << l << "\tand\t" << r << "\n";
  cout << search_max (0, n - 1, l, r, 0);
  return 0;
}
