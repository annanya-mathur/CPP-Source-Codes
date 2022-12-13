#include <bits/stdc++.h>

using namespace std;
int p=31,mod=10e7+9,num=10e3+5;
vector<long long>power(num);

long long calHash(string s)
{
    long long h=0;
    for(int i=0;i<s.size();i++)
    {
        h+=((s[i]-'a'+1)*power[i])%mod;
    }
    return h;
}
int calculateDis(vector<string> s)
{
    power[0]=1;
    int dis=1;
    for(int i=1;i<s.size();i++)
    {
        power[i]=(power[i-1]*p)%mod;
    }
    
     vector<long long> hash;
    for(auto &i:s)
    {
      hash.push_back(calHash(i));
    }
    
    sort(hash.begin(),hash.end());
    for(int i=1;i<hash.size();i++)
    {
        if(hash[i]!=hash[i-1])
        dis++;
    }
    return dis;
}


int main()
{
    int n;
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    cout<<calculateDis(s)<<endl;
    return 0;
}
