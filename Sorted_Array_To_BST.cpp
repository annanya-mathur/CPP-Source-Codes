#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
    Node (int val)
  {
    data = val;
    left = right = NULL;
  }
};

class Solution
{
public:

  Node * Bst (vector < int >&nums, int start, int end)
  {
    Node *root = NULL;
    //cout<<start<<"\t"<<end;
    if (start > end)
        return root;
    else
      {
	int mid = (start + end) / 2;
	//cout<<"%"<<nums[mid]<<"\t";
	  root = new Node (nums[mid]);


	  root->left = Bst (nums, start, mid - 1);
	  root->right = Bst (nums, mid + 1, end);
      }
  }
  vector < int >preorder (Node * root, vector < int >&r, int &i)
  {
    if (root != NULL)
      {
	r[i] = root->data;
	//cout << root->data << "\t";
	i++;
	preorder (root->left, r, i);
	preorder (root->right, r, i);
      }
    return r;

  }
  vector < int >sortedArrayToBST (vector < int >&nums)
  {

    int start = 0, end = nums.size (), i = 0;
    end--;
    //cout<<end<<"\n";
    Node *root = Bst (nums, start, end);
    //cout<<root->data;
    vector < int >r (end + 1);
    r = preorder (root, r, i);
    return r;
  }
};

int
main ()
{
  int tc;
  cin >> tc;
  while (tc--)
    {
      int n;
      cin >> n;
      vector < int >nums (n);
      for (int i = 0; i < n; i++)
	cin >> nums[i];
      Solution obj;
      vector < int >ans = obj.sortedArrayToBST (nums);
    for (auto i:ans)
	cout << i << " ";
      cout << "\n";
    }
  return 0;
}
