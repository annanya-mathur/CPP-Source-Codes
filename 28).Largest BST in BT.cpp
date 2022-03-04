#include <iostream>
#include <climits>
#include <queue>

using namespace std;

struct Node
{
  int data;
  Node *left ,* right;
    Node (int x)
  {
    data = x;
    left = right = NULL;
  }
};
struct BinaryTree
{
  int min, max, size, res;
  bool isBST;

};
BinaryTree largestBST (Node * root)
{
  if (root == NULL)
    {
      return
      {
      INT_MAX, INT_MIN, 0, 0, true};
    }
  if (root->left == NULL && root->right == NULL)
    {
      return
      {
      root->data, root->data, 1, 1, true};
    }
  BinaryTree leftNode = largestBST (root->left);
  BinaryTree rightNode = largestBST (root->right);
  BinaryTree curr;
  curr.size = (1 + leftNode.size + rightNode.size);

  if (leftNode.isBST && rightNode.isBST && leftNode.max < root->data
      && rightNode.min > root->data)
    {
      curr.isBST = true;
      curr.res = curr.size;
      curr.max = max (leftNode.max, max (rightNode.max, root->data));
      curr.min = min (leftNode.min, min (rightNode.min, root->data));
      return curr;
    }
  curr.isBST = false;
  curr.res = max (leftNode.res, rightNode.res);
  return curr;
}

Node *constructTree (Node * root ,int n ,int tree[])
{
  queue < Node * >q;
  q.push (root);
  Node *curr;
  int i = 1;

  while (q.empty () == false)
    {
      curr = q.front ();
      if (i < n)
	curr->left = new Node (tree[i++]);
      if (i < n)
	curr->right = new Node (tree[i++]);
      if (curr->left != NULL)
	q.push (curr->left);
      if (curr->right != NULL)
	q.push (curr->right);

      q.pop ();

    }
  return root;
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
  root = constructTree (root,n,tree);
  BinaryTree curr = largestBST (root);
  cout << curr.res << endl;
  return 0;
}
