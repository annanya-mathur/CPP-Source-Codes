#include <iostream>
#include <deque>
#include <vector>
using namespace std;
vector<int> pQueries(vector<int>& queries, int n) {
        deque<int>dq;
        vector<int>res;
        for(int i=1;i<=n;i++)
        {
            dq.push_back(i);
        }
        int m=queries.size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(queries[i]==dq[j])
                { int x=dq[j];
                    res.push_back(j);
                    dq.erase(dq.begin()+j);
                    dq.push_front(x);
                }
            }
        }
        return res;
    }
int main()
{
   int m,n;
   cin>>m>>n;
   vector<int>queries(m);
   for(int i=0;i<m;i++)
   {
       cin>>queries[i];
   }
   vector<int>v=pQueries(queries,n);
   for(auto i:v)
   cout<<i<<" ";
   cout<<endl;
    return 0;
}
