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
void constructTree (Node * root, int tree[], int n)
{
  queue < Node * >q;
  q.push (root);
  Node *curr;
  int i = 1;
  int level = 1, max = 0;
  while (q.empty () == false && i < n && curr != NULL)
    {
      curr = q.front ();
      curr->left = new Node (tree[i++]);
      max++;

      if (i < n)
	{
	  curr->right = new Node (tree[i++]);
	  max++;
	}

      if (curr->left != NULL)
	q.push (curr->left);

      if (curr->right != NULL)
	q.push (curr->right);

      q.pop ();

    }
  return;
}

void preorder (Node * root)
{
  if (root != NULL)
    {
      cout << root->data<<"\t";
      preorder (root->left);
      preorder (root->right);
    }
  return;
}

int main ()
{
  int n;
  cin >> n;
  int tree[n];
  for (int i = 0; i < n; i++)
    {
      cin >> tree[i];
    }
  Node *root = new Node (tree[0]);
  constructTree (root, tree, n);
  preorder (root);
  return 0;
}
