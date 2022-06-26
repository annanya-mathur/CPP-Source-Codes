#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pQueries(vector<int>& queries, int n) {
        vector<int>res;
        vector <int>permute(n);
        for(int i=1;i<=n;i++)
            permute[i-1]=i;
        int m=queries.size();
        for(auto i:queries)
        {
            auto pos=std::find(permute.begin(),permute.end(),i);
            res.push_back(pos-permute.begin());
            permute.erase(pos);
            permute.insert(permute.begin(),i);
            
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
