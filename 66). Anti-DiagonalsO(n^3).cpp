#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > anti_diagonal(vector<vector<int> > &a) {
int count=0,n=a[0].size(),flag=n*n;
vector<vector<int>>res;
while(flag)
{ 
vector<int>temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i+j==count)
            {temp.push_back(a[i][j]);
            flag--;}
            
        }
    }
    count++;
    res.push_back(temp);
}
return res;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++)
    { vector<int>temp;
        for(int j=0;j<n;j++)
        {
            int q;
            cin>>q;
            
           temp.push_back(q);
        }
        v.push_back(temp);
    }
    vector<vector<int>>res=anti_diagonal(v);
    for(auto i:res)
    {
        for(auto j:i)
        cout<<j<<"\t";
        cout<<endl;
    }
    return 0;
}
