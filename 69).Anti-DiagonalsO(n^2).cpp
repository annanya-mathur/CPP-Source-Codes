#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > anti_diagonal(vector<vector<int> > &a) {
int n=a[0].size();
vector<vector<int>>res;
for(int i=0;i<n;i++)
{
    vector<int>temp;
    int r=0,c=i;
    while(c>=0)
    {
        temp.push_back(a[r][c]);
        r++;
        c--;
    }
    res.push_back(temp);
}
for(int i=1;i<n;i++)
{
    vector<int>temp;
    int r=i,c=n-1;
    while(r<n)
    {
        temp.push_back(a[r][c]);
        r++;
        c--;
    }
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
