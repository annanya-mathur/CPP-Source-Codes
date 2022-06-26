#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin(),v.end());
        vector<vector<int>>res;
        int n=v.size();
        for(int i=0;i<n;i++)
        { if(i==0 || (i>0 &&v[i]!=v[i-1]))
        { 
             int t=0-v[i],l=i+1,h=n-1;
            while(l<h)
            {
                if((v[l]+v[h])<t) l++;
                else if ((v[l]+v[h])>t) h--;
                else
                {
                    res.push_back({v[i],v[l],v[h]});
                    while(l<h && v[l]==v[l+1]) l++;
                    while(l<h && v[h]==v[h-1]) h--;
                    l++,h--;

                }
            }
        } 
        }
        return res;
    }
int main()
{  
   int n;
   cin>>n;
   vector<int>v(n);
   vector<vector<int>> res;

       for(int j=0;j<n;j++ )
       {
           cin>>v[j];
       }

   res=threeSum(v);
   for(auto i:res)
   {
       for(auto j:i)
       {
           cout<<j<<" ";
       }
       cout<<endl;
   }

    return 0;
}
