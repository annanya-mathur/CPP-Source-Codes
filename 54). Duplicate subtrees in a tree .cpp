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

string serialize (Node * root, map < string, int >&mp)
{
  if (!root)
    return "N";
  string s = to_string (root->data);
  if (!root->left && !root->right)
    return s;
  s += serialize (root->left, mp) + serialize (root->right, mp);
  mp[s]++;
  return s;

}

int duplicateTree (Node * root)
{
  map < string, int >mp;
  serialize (root, mp);
for (auto i:mp)
    {
      cout << i.first << "\t" << i.second << endl;
    }
  cout << "Duplicate SubTrees" << endl;
  int c = 0;
for (auto i:mp)
    {
      if (i.second == 2)
	{
	  c++;
	  cout << i.first << endl;
	}
    }
  return c;
}

int main ()
{
  Node *root = new Node (1);
  root->left = new Node (2);
  root->left->left = new Node (4);

  root->left->left->right = new Node (7);
  root->right = new Node (4);
  root->right->right = new Node (7);

  cout << "No of duplicate SubTrees" << endl;
  cout << duplicateTree (root);


  return 0;
}
