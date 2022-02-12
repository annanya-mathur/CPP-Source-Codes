#include <bits/stdc++.h>

using namespace std;
struct trie
{
  trie *child[26];
  bool isEnd;
    trie ()
  {
    for (int i = 0; i < 26; i++)
      {
	child[i] = NULL;
	isEnd = false;
      }
  }
};
void insert (trie * root, string s, int n)
{
  trie *curr = root;


  for (int i = 0; i < s.size (); i++)
    {
      int index = s[i] - 'a';
      if (curr->child[index] == NULL)
	curr->child[index] = new trie ();
      curr = curr->child[index];
    }
  curr->isEnd = true;


}

bool search (trie * root, string s)
{
  trie *curr = root;
  for (int i = 0; i < s.size (); i++)
    {
      int index = s[i] - 'a';
      if (curr->child[index] == NULL)
	return false;
      curr = curr->child[index];
    }
 return isEnd;
}

int main ()
{
  string dic[] = { "bad", "bat", "geek", "geeks", "cat", "cut", "zoo" };
  trie *root = new trie ();
  int n = 7;
  for (int i = 0; i < n; i++)
    insert (root, dic[i], n);
  for (int i = 0; i < n; i++)
    {
      cout << search (root, dic[i]) << "\t";
    }
    cout<<endl;
    cout<<search(root,"abc")<<"\t";
  return 0;
}
