#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node *left, *right;
    node (int x)
  {
    data = x;
    left = right = NULL;
  }
};
int preIndex = 0;
void inorderTree (node * root)
{
  if (root != NULL)
    {
      inorderTree (root->left);
      cout << root->data << "\t";
      inorderTree (root->right);
    }
  return;
}

node *constructTree (int inorder[], int preorder[], int start, int end)
{
  if (start > end)
    return NULL;
  node *root = new node (preorder[preIndex]);
  int inIndex;
  for (int i = start; i <= end; i++)
    {
      if (inorder[i] == preorder[preIndex])
	{
	  inIndex = i;
	  break;
	}
    }
  preIndex++;
  root->left = constructTree (inorder, preorder, start, inIndex - 1);
  root->right = constructTree (inorder, preorder, inIndex + 1, end);
  return root;
}

int main ()
{
  int n;
  cin >> n;
  int inorder[n], preorder[n];
  for (int i = 0; i < n; i++)
    {
      cin >> inorder[i];
    }
  for (int i = 0; i < n; i++)
    {
      cin >> preorder[i];
    }
  node *root = constructTree (inorder, preorder, 0, n - 1);
  inorderTree (root);
  return 0;
}
