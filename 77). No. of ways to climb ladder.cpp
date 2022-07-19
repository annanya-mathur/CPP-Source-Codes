#include <iostream>
int wayesLadder(int n)
{
    if(n<0) return 0;
    if(n==1 || n==0) return 1;
    return wayesLadder(n-1)+wayesLadder(n-2)+wayesLadder(n-3);
}
using namespace std;

int main()
{
   int n;
   cin>>n;
   cout<<wayesLadder(n)<<endl;

    return 0;
}
