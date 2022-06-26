#include<bits/stdc++.h>

using namespace std;
typedef  pair<int,pair<int,int>>pairs;

vector<vector<int>> threeSum(vector<int>& v) {
        int n=v.size();
        vector<vector<int>>res;
        map<int,int>mp;
        
        for(int i=0;i<n;i++)
            mp[v[i]]++;
       
        set<pairs>st;
        
        for(int i=0;i<n;i++)
        { if(mp[v[i]]==1)
            mp.erase(v[i]);
         else
            mp[v[i]]-=1;
            for(int j=i+1;j<n;j++)
            {if(mp[v[j]]==1)
            mp.erase(v[j]);
         else
            mp[v[j]]-=1;
             
                int p=0-v[i]-v[j];
             
                    if(mp.find(p)!=mp.end())
                        
                    {  multiset<int>s;
                     
                     s.insert(v[i]);
                     s.insert(v[j]);
                     s.insert(p);
                     int a,b,c;
                    auto it=s.begin(); 
                     a=*it; it++;
                     b=*it ; it++;
                     c=*it;
                    
                        pair y=make_pair(b,c);
                       pairs x=make_pair(a,y);
                        st.insert(x);
                     
                    }
                mp[v[j]]++;
            }
         mp[v[i]]++;
        }
      for(auto i:st)
      {vector<int>temp;
          temp.push_back(i.first);
       temp.push_back(i.second.first);
       temp.push_back(i.second.second);
       res.push_back(temp);
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
