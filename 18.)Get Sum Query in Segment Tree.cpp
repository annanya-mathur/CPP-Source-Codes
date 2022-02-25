#include <iostream>
#include <cmath>

using namespace std;

int arr[10000], tree[40000];

void constructST (int start, int end, int index)
{
  if (start == end)
    {
      tree[index] = arr[start];
      return;
    }
  int mid = (start + end) / 2;
  constructST (start, mid, 2 * index + 1);
  constructST (mid + 1, end, 2 * index + 2);
  tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
}

int getSum (int l, int r, int start, int end, int index)
{
  if (end < l || start > r)
    return 0;
  if (start >= l && end <= r)
    return tree[index];
  int mid = (start + end) / 2;
  return getSum (l, r, start, mid, 2 * index + 1) + getSum (l, r, mid + 1,end,2 * index + 2);
}

int main ()
{
  int n, l, r;
  cin >> n;
  int x = (int)(ceil (log2 (n)));
  int size = (2 * (int) pow (2, x)) - 1;

  for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
  constructST (0, n - 1, 0);

  cout << "SEGMENT TREE FORMED" << endl;
  for (int i = 0; i < size; i++)
    {
      cout << tree[i] << "\t";
    }
  cout << endl;
  cin >> l >> r;
  cout << "SUM BETWEEN " << l << " " << "&" << " " << r << "\t" << getSum (l,r,0,n -1,0);

  return 0;
}
