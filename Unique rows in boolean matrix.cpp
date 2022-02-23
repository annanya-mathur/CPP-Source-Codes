#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;
struct trie
{
  trie *child[2];
    trie ()
  {
    for (int i = 0; i < 2; i++)
      {
	child[i] = NULL;
  }}
};

trie *root = new trie ();

bool insertTrie (vector < int >row_mat)
{
  trie *curr = root;
  bool insert = false;
  for (int i = 0; i < row_mat.size (); i++)
    {
      int index = row_mat[i];
      if (curr->child[index] == NULL)
	{
	  insert = true;
	  curr->child[index] = new trie ();

	}

      curr = curr->child[index];
    }
  return insert;
}

vector < vector < int >>uniqueRow (int v[MAX][MAX], int row, int col)
{
  vector < vector < int >>res;
  for (int i = 0; i < row; i++)
    {
      vector < int >temp;
      for (int j = 0; j < col; j++)
	{
	  temp.push_back (v[i][j]);
	}
      if (insertTrie (temp) == true)
	{
	  res.push_back (temp);
	}

    }
  return res;
}

int main ()
{
  int row, col;
  cin >> row >> col;
  int mat[MAX][MAX];
  for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
	{
	  cin >> mat[i][j];
	}
    }
  vector < vector < int >>res = uniqueRow (mat, row, col);
  for (int i = 0; i < res.size (); i++)
    {
    for (auto & x:res[i])
	cout << x << "\t";
      cout << endl;
    }

  return 0;
}
