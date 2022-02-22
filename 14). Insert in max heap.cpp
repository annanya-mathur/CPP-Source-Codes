#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector < int >heap;
void heapify (int i, int n)
{
  int l = 2 * i + 1, r = 2 * i + 2, large = i;
  if (l < n && heap[l] > heap[large])
    large = l;
  if (r < n && heap[r] > heap[large])
    large = r;
  if (large != i)
    {
      swap (heap[i], heap[large]);
      heapify (large, n);
    }
  return;

}

void insert_heap (int i)
{
  int parent = floor ((i - 1) / 2);
  if (heap[i] > heap[parent])
    {
      swap (heap[i], heap[parent]);
      insert_heap (parent);
    }
  return;
}

int main ()
{
  int n, x;
  cin >> n;


  for (int i = 0; i < n; i++)
    {
      int q;
      cin >> q;
      heap.push_back (q);
    }
  int index = n / 2 - 1;
  for (int i = index; i >= 0; i--)
    {
      heapify (i, n);
    }
  cin >> x;
  heap.push_back (x);
  insert_heap (n);
for (auto & i:heap)
    {
      cout << i << "\t";
    }
  return 0;
}
