#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int tree[100000], arr[100000];
void SegmentTree (int start, int end, int index)
{
  if (start == end)
    {
      tree[index] = arr[start];
      return;
    }
  int mid = (start + end) / 2;
  SegmentTree (start, mid, 2 * index + 1);
  SegmentTree (mid + 1, end, 2 * index + 2);
  tree[index] = tree[2 * index + 1] + tree[2 * index + 2];

}

int main ()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }


  int x = (int) (ceil (log2 (n)));

  int size_st = (2 * (int) pow (2, x)) - 1;


  SegmentTree (0, n - 1, 0);
  for (int i = 0; i < size_st; i++)
    {
      cout << tree[i] << "\t";
    }
  return 0;
}
