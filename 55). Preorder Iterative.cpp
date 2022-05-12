#include <bits/stdc++.h>
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

void IteraPreorder (Node * root)
{
  stack < Node * >st;
  Node *curr = root;
  while (curr || !st.empty ())
    {
      while (curr)
	{
	  cout << curr->data << "\t";
	  if (curr->right)
	    st.push (curr->right);
	  curr = curr->left;

	}
      if (!st.empty ())
	{
	  curr = st.top ();
	  st.pop ();
	}
    }
}

int main ()
{
  Node *root = new Node (1);
  root->left = new Node (2);
  root->left->left = new Node (4);

  root->left->left->right = new Node (7);
  root->right = new Node (5);
  root->right->right = new Node (6);

  IteraPreorder (root);

  return 0;
}
