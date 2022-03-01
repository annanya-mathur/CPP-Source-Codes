#include <iostream>

using namespace std;

string sub="";

int lcs(string s1,string s2,int n,int m)
{
    if(n==0 ||m==0)
    return 0;
    if(s1[n-1]==s2[m-1])
    {
        sub+=s1[n-1];
       
        return 1+lcs(s1,s2,n-1,m-1);
    }
    return max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<"LONGEST COMMOM SUBSEQUENCE\t";
    int x=lcs(s1,s2,s1.size(),s2.size());
    cout<<sub<<"\n"<<"WITH LENGTH"<<"\t"<<x<<endl;

    return 0;
}
