#include <iostream>
using namespace std;

int first = -1, last = -1;
void occurrence (string s, char a, int n)
{
  if (n < 0)
    return;
  if (s[n] == a)
    {
      if (last == -1)
	{
	  last = n;

	}
      first = n;
    }
  occurrence (s, a, n - 1);
}

int main ()
{
  int n;
  string s;
  char a;
  cin >> s;
  cin >> a;
  n = s.size ();
  occurrence (s, a, n - 1);
  if (first == -1)
    cout << "String not found" << endl;
  else
    cout << "FIRST OCCURRENCE " << first +
      1 << "\n" << "LAST OCCURRENCE " << last + 1 << endl;
  return 0;
}
