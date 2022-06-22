#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> shuffle(vector<int>& n1, vector<int>& n2) {
        int n=n1.size();
        vector<int>a,v(n);
        a.assign(n1.begin(),n1.end());
        
        sort(a.begin(),a.end());
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({n2[i],i});
            
        }
        int s=0,b=n-1;
        while(!pq.empty())
        {int i=pq.top().second;
            if(a[b]>pq.top().first)
            {
                
                v[i]=a[b];
                b--;
            }
            else
            {
                v[i]=a[s];
                s++;   
            }
         pq.pop();
        }
        return v;
    }

int main()
{
    int n;
    cin>>n;
    vector<int>n1;
    vector<int>n2;
    for(int i=0;i<n;i++)
    {
        int q;
        cin>>q;
        n1.push_back(q);
    }
     for(int i=0;i<n;i++)
    {
        int q;
        cin>>q;
        n2.push_back(q);
    }
    vector<int>v=shuffle(n1,n2);
    for(auto i :v)
    cout<<i<<"\t";
    return 0;
}
