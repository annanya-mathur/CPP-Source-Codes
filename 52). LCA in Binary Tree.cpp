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

Node *LcaBT (Node * root, int a, int b)
{
  if (!root)
    return NULL;
  if (root->data == a || root->data == b)
    return root;
  Node *l = LcaBT (root->left, a, b);
  Node *r = LcaBT (root->right, a, b);

  if (l && r)
    return root;
  if (!l)
    return r;
  if (!r)
    return l;
  return NULL;
}

int main ()
{

  Node *root = new Node (5);
  root->left = new Node (2);
  root->right = new Node (10);
  root->left->left = new Node (3);
  root->left->right = new Node (4);
  Node *lca = LcaBT (root, 3, 4);
  cout << lca->data << endl;
  return 0;
}
