#include <iostream>

using namespace std;
struct trie
{
    trie* child[26];
    bool isEnd;
    trie()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
        child[i]=NULL;
    }
};
trie *root=new trie();
bool isEmpty(trie *node)
{
    for(int i=0;i<26;i++)
    {
        if(node->child[i]!=NULL)
        return false;
    }
    return true;
}
trie* delete_key(trie *root,string s,int i)
{
    if(root==NULL)
    return NULL;
    if(i==s.size())
    {
        root->isEnd=false;
        if(isEmpty(root)==true)
        {delete(root);
        root=NULL;}
        return root;
    }
    root->child[s[i]-'a']=delete_key(root->child[s[i]-'a'],s,i+1);
    if(isEmpty(root)==true && root->isEnd==false)
    {delete(root);
    root=NULL;}
    return root;
}

void insert(string s)
{
    trie* curr=root;
    for(int i=0;i<s.size();i++)
    {
        if(curr->child[s[i]-'a']==NULL)
        curr->child[s[i]-'a']=new trie();
        curr=curr->child[s[i]-'a'];
    }
    curr->isEnd=true;
}
bool search(string s)
{
    trie* curr=root;
    for(int i=0;i<s.size();i++)
    {
        if(curr->child[s[i]-'a']==NULL)
        return false;
        curr=curr->child[s[i]-'a'];
    }
    return (curr->isEnd);
}
int main()
{
    int n;
    cin>>n;
    string s[n],key;
    for(int i=0;i<n;i++)
    {cin>>s[i];
    insert(s[i]);
    }
    cin>>key;
    delete_key(root,key,0);
    cout<<search(key)<<"\t";
    key="and";
    cout<<search(key);
    return 0;
}
