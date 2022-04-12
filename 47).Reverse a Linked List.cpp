#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
    Node (int x)
  {
    data = x;
    next = NULL;
  }
};

Node *reverse (Node * root)
{
  Node *prev = root->next;
  Node *curr = root->next->next;
  prev->next = root;
  root->next = NULL;
  while (curr != NULL)
    {
      Node *temp = curr;
      curr = curr->next;
      temp->next = prev;
      prev = temp;
    }

  return prev;

}



int main ()
{
  int n;
  cin >> n;
  int arr[n];
  Node *curr, *root = NULL;
  for (int i = 0; i < n; i++)
    {

      cin >> arr[i];
    }
  for (int i = 0; i < n; i++)
    {
      if (root == NULL)
	{
	  curr = new Node (arr[i]);
	  root = curr;
	}
      else
	{
	  curr->next = new Node (arr[i]);
	  curr = curr->next;
	}

    }
  curr->next = NULL;
  Node *t = root;
  while (t != NULL)
    {
      cout << t->data << "\t";
      t = t->next;
    }
  cout << endl;
  root = reverse (root);
  curr = root;
  while (curr != NULL)
    {
      cout << curr->data << "\t";
      curr = curr->next;
    }
  return 0;
}
