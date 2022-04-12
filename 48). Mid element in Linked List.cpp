#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
    node (int x)
  {
    data = x;
    next = NULL;
  }
};

int midE (node * root)
{
  node *fast = root, *slow = root;
  while (fast && fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
    }
  return slow->data;
}

int main ()
{
  int n;
  cin >> n;
  node *root = NULL, *curr;
  for (int i = 0; i < n; i++)
    {
      int q;
      cin >> q;
      if (root == NULL)
	{
	  root = new node (q);
	  curr = root;
	}
      else
	{
	  curr->next = new node (q);
	  curr = curr->next;
	}
    }
  curr->next = NULL;
  curr = root;
  while (curr != NULL)
    {
      cout << curr->data << "\t";
      curr = curr->next;
    }
  cout << endl;
  cout << "Mid Element" << "\t";
  cout << midE (root) << endl;
  return 0;
}
