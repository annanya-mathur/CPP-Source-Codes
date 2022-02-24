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
void inorder (Node * root)
{
  if (root != NULL)
    {

      inorder (root->left);
      cout << root->data << "\t";
      inorder (root->right);
    }
  return;
}

Node *construct_BST (Node * root, int bst[], int start, int end)
{
  if (start > end)
    return NULL;
  int mid = (start + end) / 2;
  root = new Node (bst[mid]);
  root->left = construct_BST (root, bst, start, mid - 1);
  root->right = construct_BST (root, bst, mid + 1, end);
  return root;
}

int main ()
{
  int n;
  cin >> n;
  int bst[n];
  for (int i = 0; i < n; i++)
    cin >> bst[i];
  sort (bst, bst + n);
  Node *root;
  root = construct_BST (root, bst, 0, n - 1);
  //cout<<root->data;
  inorder (root);
  return 0;
}
