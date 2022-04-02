#include <iostream>
using namespace std;

class avl
{
public:
  int data;
  avl *left, *right;
  int height;
};

avl *newNode (int k)
{
  avl *curr = new avl ();
  curr->data = k;
  curr->right = NULL;
  curr->left = NULL;
  curr->height = 1;
  return curr;
}

int height (avl * curr)
{
  if (curr == NULL)
    return 0;
  else
    return curr->height;
}

int balFactor (avl * curr)
{
  if (curr == NULL)
    return 0;
  return height (curr->left) - height (curr->right);
}

avl *leftRotation (avl * curr)
{
  avl *x = curr->right;
  avl *t = x->left;
  x->left = curr;
  curr->right = t;
  curr->height = max (height (curr->left), height (curr->right)) + 1;
  x->height = max (height (x->left), height (x->right)) + 1;
  return x;
}

avl *rightRotation (avl * curr)
{
  avl *x = curr->left;
  avl *t = x->right;
  x->right = curr;
  curr->left = t;
  curr->height = max (height (curr->left), height (curr->right)) + 1;
  x->height = max (height (x->left), height (x->right)) + 1;
  return x;

}

avl *insertAvl (avl * root, int val)
{
  if (root == NULL)
    return (newNode (val));
  if (root->data > val)
    root->left = insertAvl (root->left, val);
  else if (root->data < val)
    root->right = insertAvl (root->right, val);
  else
    return root;
  root->height = max (height (root->left), height (root->right)) + 1;
  int bal = balFactor (root);

  if (bal > 1 && val < root->data)
    return rightRotation (root);

  if (bal < 1 && val > root->data)
    return leftRotation (root);

  if (bal > 1 && val > root->data)
    {
      avl *root = leftRotation (root);
      return rightRotation (root);
    }

  if (bal < 1 && val < root->data)
    {
      avl *root = rightRotation (root);
      return leftRotation (root);
    }

  return root;


}

void preorder (avl * root)
{
  if (root != NULL)
    {
      cout << root->data << "\t";
      preorder (root->left);
      preorder (root->right);
    }
  return;
}

int main ()
{
  int n;
  cin >> n;
  avl *root = NULL;
  for (int i = 0; i < n; i++)
    {
      int q;
      cin >> q;

      root = insertAvl (root, q);
    }
  preorder (root);

  return 0;
}
