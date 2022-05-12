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
Node *target;

void findParent (Node * root, map < Node *, Node * >&parent, int t)
{
  if (!root)
    return;
  if (root->data == t)
    target = root;
  if (root->left)
    parent[root->left] = root;
  if (root->right)
    parent[root->right] = root;
  findParent (root->left, parent, t);
  findParent (root->right, parent, t);
}

int burningTime (Node * root, int t)
{
  map < Node *, Node * >parent;
  // cout<<"Parent Map"<<endl;
  findParent (root, parent, t);
  // for(auto i:parent)
  // cout<<i.first->data<<"\t"<<i.second->data<<endl;
  queue < Node * >q;
  q.push (target);
  map < Node *, int >visited;
  visited[target] = 1;
  int maxTime = 0;
  while (!q.empty ())
    {
      int s = q.size ();
      int flag = 0;
      while (s--)
	{
	  Node *curr = q.front ();
	  q.pop ();
	  if (curr->left && !visited[curr->left])
	    {
	      flag = 1;
	      visited[curr->left] = 1;
	      q.push (curr->left);
	    }
	  if (curr->right && !visited[curr->right])
	    {
	      flag = 1;
	      visited[curr->right] = 1;
	      q.push (curr->right);
	    }
	  if (parent[curr] && !visited[parent[curr]])
	    {
	      flag = 1;
	      visited[parent[curr]] = 1;
	      q.push (parent[curr]);
	    }
	}
      if (flag)
	maxTime++;
    }
  return maxTime;
}

int main ()
{
  Node *root = new Node (1);
  root->left = new Node (2);
  root->left->left = new Node (4);
  root->left->right = new Node (7);
  root->right = new Node (3);
  root->right->left = new Node (5);
  root->right->right = new Node (6);


  cout << "Buring Time from node 2:-" << "\t";
  cout << burningTime (root, 2) << endl;

  cout << "Buring Time from node 3:-" << "\t";
  cout << burningTime (root, 3) << endl;

  cout << "Buring Time from node 4:-" << "\t";
  cout << burningTime (root, 4) << endl;

  cout << "Buring Time from node 6:-" << "\t";
  cout << burningTime (root, 6) << endl;

  return 0;
}
