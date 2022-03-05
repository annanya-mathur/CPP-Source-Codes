#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node *left, *right;
    Node (int x)
  {
    data = x;
    left = right = NULL;
  }
};
Node *root;

Node *floorBST (int n)
{
  Node *curr = root, *res = NULL;

  while (curr)
    {
      if (curr->data == n)
	return curr;
      else if (curr->data > n)
	{
	  curr = curr->left;
	}
      else
	{
	  res = curr;
	  curr = curr->right;
	}
    }
  return res;
}

Node *ceilBST (int n)
{
  Node *curr = root, *res = NULL;

  while (curr)
    {
      if (curr->data == n)
	return curr;
      else if (curr->data > n)
	{
	  res = curr;
	  curr = curr->left;
	}
      else
	{
	  curr = curr->right;
	}
    }
  return res;
}

int main ()
{
  int n;
  cin >> n;
  root = new Node (10);
  root->left = new Node (5);
  root->right = new Node (15);
  root->right->left = new Node (12);
  root->right->right = new Node (30);
  Node *f = floorBST (n);
  Node *c = ceilBST (n);

  if (f == NULL)
    {
      cout << "Floor of " << n << " not found" << endl;
    }
  else
    {
      cout << "Floor of " << n << "\t" << f->data << endl;
    }
  if (c == NULL)
    {
      cout << "Ceil of " << n << " not found" << endl;
    }
  else
    {
      cout << "Ceil of " << n << "\t" << c->data << endl;
    }


  return 0;
}
