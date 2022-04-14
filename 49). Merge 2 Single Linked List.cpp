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

Node *merge (Node * head1, Node * head2)
{
  Node *res = NULL;
  if (head1 == NULL)
    return head2;
  if (head2 == NULL)
    return head1;

  if (head1->data <= head2->data)
    {
      res = head1;
      res->next = merge (head1->next, head2);
    }
  else
    {
      res = head2;
      res->next = merge (head1, head2->next);
    }
  return res;
}

int main ()
{
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  Node *head1 = NULL, *head2 = NULL, *curr1 = NULL, *curr2 = NULL;
  for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (head1 == NULL)
	{
	  head1 = new Node (a[i]);
	  curr1 = head1;
	}
      else
	{
	  curr1->next = new Node (a[i]);
	  curr1 = curr1->next;
	}
    }
  curr1->next = NULL;
  for (int j = 0; j < m; j++)
    {
      cin >> b[j];
      if (head2 == NULL)
	{
	  head2 = new Node (b[j]);
	  curr2 = head2;
	}
      else
	{
	  curr2->next = new Node (b[j]);
	  curr2 = curr2->next;
	}
    }
  curr2->next = NULL;
  curr1 = head1;
  curr2 = head2;
  while (curr1)
    {
      cout << curr1->data << "\t";
      curr1 = curr1->next;
    }
  cout << endl;
  while (curr2)
    {
      cout << curr2->data << "\t";
      curr2 = curr2->next;
    }
  cout << endl;
  Node *res = merge (head1, head2);
  Node *temp = res;
  while (temp)
    {
      cout << temp->data << "\t";
      temp = temp->next;
    }
  return 0;
}
