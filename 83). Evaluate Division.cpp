class Solution {
private: vector<double>res;
         unordered_map<string,vector<pair<string,double>> >mp;
         unordered_set<string>s;

public:
    void dfs(string s, string d,double &ans,unordered_map<string,int>&vis,double temp)
    { 
        if(vis.count(s))
        return;
        if(s==d)
        {
            ans=temp;
            return;
        }
        auto i=mp[s];
        vis[s]=1;
        for(auto x:i)
        {
            
            dfs(x.first,d,ans,vis,temp*x.second);
        }
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
   mp.clear();
   res.clear();
   s.clear();
   for(int i=0;i<e.size();i++)
   {
       mp[e[i][0]].push_back({e[i][1],v[i]});
       mp[e[i][1]].push_back({e[i][0],1.0/v[i]});
       s.insert(e[i][0]);
       s.insert(e[i][1]);

   }    
    for(int i=0;i<q.size();i++)
    {
        double ans=-1.0,temp=1;
      unordered_map<string,int>vis;
     
      if((s.find(q[i][0])!=s.end()) || (s.find(q[i][1])!=s.end()))
        dfs(q[i][0],q[i][1],ans,vis,temp);
        res.push_back(ans);
    }
    
    return res;
    }
};
