#include <iostream>
#include<vector>
using namespace std;
void heapify (vector <int>&heap, int i, int n)
{
  int l = 2 * i + 1, r = 2 * i + 2, large = i;
  if (l < n && heap[large] < heap[l])
    large = l;
  if (r < n && heap[large] < heap[r])
    large = r;
  if (large != i)
    {
      swap (heap[large], heap[i]);
      heapify (heap, large, n);
    }
}

int main ()
{
  int n;
  cin >> n;
  vector < int >heap (n, 0);
  for (int i = 0; i < n; i++)
    cin >> heap[i];
  int index = (n/2)-1;
  for (int i = index; i >= 0; i--)
    heapify (heap, i, n);
for (auto & i:heap)
    cout << i << "\t";
  return 0;
}
