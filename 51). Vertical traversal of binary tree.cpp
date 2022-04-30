#include <iostream>
#include <queue>
#include<map>

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


void verticalTraversal (Node * root)
{
  map < int, map < int, vector < int >>>mp;
  queue < pair < Node *, pair < int, int >>>q;
  q.push ({root,{0, 0}});
  
  while (q.empty () == false)
    {
      auto x = q.front ();
      q.pop ();
      Node *y = x.first;
      int i = x.second.first, j = x.second.second;
      mp[i][j].push_back (y->data);
      if (y->left != NULL)
	{
	  q.push ({y->left,{i - 1, j + 1}});
	}
      if (y->right != NULL)
	{
	  q.push ({y->right,{i + 1, j + 1}});
	}
    }
  cout << "Vertical Traversal of Tree" << endl;
  vector < int >res;
for (auto i:mp)
    {
    for (auto j:i.second)

	{
	  res.insert (res.end (), j.second.begin (), j.second.end ());
	}

    }
for (auto x:res)
    cout << x << "\t";
}

int main ()
{
  Node *root = new Node (1);
  root->left = new Node (2);
  root->right = new Node (3);
  root->left->left = new Node (4);
  root->left->right = new Node (5);
  root->right->left = new Node (6);
  root->right->right = new Node (7);
  root->right->left->right = new Node (8);
  root->right->right->right = new Node (9);
  verticalTraversal (root);

  return 0;
}
