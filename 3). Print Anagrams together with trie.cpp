#include <bits/stdc++.h>

using namespace std;
struct trie
{
    trie* child[26];
    bool isEnd;
    string s;
    trie()
    {
        isEnd=false;
        s="";
        for(int i=0;i<26;i++)
        child[i]=NULL;
    }
};
trie *root= new trie;
void insert(string s , int index)
{
    trie *curr=root;
    for(int i=0;i<s.size();i++)
    { if(curr->child[s[i]-'a']==NULL)
        curr->child[s[i]-'a']= new trie();
        curr=curr->child[s[i]-'a'];
    }
    if(!curr->isEnd)
    curr->isEnd=true;
    curr->s+=to_string(index);
   
}
void search(string s, string st[])
{
    trie *curr=root;
    for(int i=0;i<s.size();i++)
    curr=curr->child[s[i]-'a'];
    string a=curr->s;
    for(int i=0;i<a.size();i++)
    {  string y="";
       y+=a[i];
        int x=stoi(y);
        cout<<st[x]<<"\t";
    }
    cout<<"\n";
}
int main()
{   int n;
cin>>n;
set<string>a;
    string st[n],b[n];
    for(int i=0;i<n;i++)
    {cin>>st[i];
    b[i]=st[i];}
    for(int i=0;i<n;i++)
    {
        sort(b[i].begin(),b[i].end());
        a.insert(b[i]);
        insert(b[i],i);
    }
    for(auto &i:a)
    {   
        search(i,st);
    }

    return 0;
}
