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

Node* constructTree (string tree[], int n)
{
  if(n==0 || tree[0]=="null")
  return NULL;
  Node *root= new Node(stoi(tree[0]));
  int i=1;
  queue<Node*> q;
  q.push(root);
   while (q.empty () == false)
    {
     Node * curr = q.front ();
      if (i < n && tree[i]!="null")
	{curr->left = new Node (stoi(tree[i]));

	}
 i++;
      if (i < n && tree[i]!="null")

	{curr->right = new Node (stoi(tree[i]));

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
  Node *root = constructTree(tree,n);
 
 preorder (root);
  return 0;
}



