#include <iostream>
#include <string.h>
#include <climits>
using namespace std;

int editDis (string s1, string s2, int n, int m)
{
  if (n == 0)
    return m;
  if (m == 0)
    return n;
  if (s1[n - 1] == s2[m - 1])
    return editDis (s1, s2, n - 1, m - 1);
  else
    return 1 + min ((editDis (s1, s2, n, m - 1), editDis (s1, s2, n - 1, m)),
		    editDis (s1, s2, n - 1, m - 1));


}

int main ()
{
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size (), m = s2.size ();
  cout << "String 1" << "\t" << s1 << "\t" << "String 2" << "\t" << s2 <<"\n";
  cout << "Edit Distance" << "\t";
  cout << editDis (s1, s2, n, m);

  return 0;
}
