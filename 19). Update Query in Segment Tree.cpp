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

void update (int start, int end, int diff, int ind, int index)
{
  if (ind < start || ind > end)
    return;
  tree[index] += diff;
  if (start < end)
    {
      int mid = (start + end) / 2;

      update (start, mid, diff, ind, 2 * index + 1);
      update (mid + 1, end, diff, ind, 2 * index + 2);
    }
}

int main ()
{
  int n, value, ind;
  cin >> n;
  int x = (int) (ceil (log2 (n)));
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
  cin >> ind >> value;
  cout << "After Updating value " << value << " " << "at " << ind << endl;
  int diff = value - arr[ind];

  update (0, n - 1, diff, ind, 0);
  cout << "SEGMENT TREE FORMED" << endl;
  for (int i = 0; i < size; i++)
    {
      cout << tree[i] << "\t";
    }

  return 0;
}
