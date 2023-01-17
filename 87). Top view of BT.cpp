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

void topView (Node * root)
{
  map < int, int >mp;
  queue < pair < Node *, int >>q;
  q.push (
	   {
	   root, 0});
  mp.insert (
	      {
	      0, root->data});
  while (!q.empty ())
    {
      auto it = q.front ().first;
      int x = q.front ().second;
      q.pop ();

      if (it->left)
	{
	  q.push (
		   {
		   it->left, x - 1}
	  );

	  if (mp.find (x - 1) == mp.end ())
	    {
	      mp.insert (
			  {
			  x - 1, it->left->data}
	      );
	    }
	}
      if (it->right)
	{
	  q.push (
		   {
		   it->right, x + 1}
	  );
	  if (mp.find (x + 1) == mp.end ())
	    {			// cout<<x+1<<endl;
	      mp.insert (
			  {
			  x + 1, it->right->data}
	      );
	    }
	}
    }
for (auto i:mp)
    {
      cout << i.second << " ";
    }
  cout << endl;
}

Node *constructTree (string tree[], int n)
{
  if (n == 0 || tree[0] == "null")
    return NULL;
  Node *root = new Node (stoi (tree[0]));
  int i = 1;
  queue < Node * >q;
  q.push (root);
  while (q.empty () == false)
    {
      Node *curr = q.front ();
      if (i < n && tree[i] != "null")
	{
	  curr->left = new Node (stoi (tree[i]));

	}
      i++;
      if (i < n && tree[i] != "null")

	{
	  curr->right = new Node (stoi (tree[i]));

	}
      i++;
      if (curr->left != NULL)
	q.push (curr->left);

      if (curr->right != NULL)
	q.push (curr->right);

      q.pop ();

    }

  return root;

}

void preorder (Node * root)
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
  string tree[n];
  for (int i = 0; i < n; i++)
    {
      cin >> tree[i];
    }
  Node *root = constructTree (tree, n);
  topView (root);
// preorder (root);
  return 0;
}
