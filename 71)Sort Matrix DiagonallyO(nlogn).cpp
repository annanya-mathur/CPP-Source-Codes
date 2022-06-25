#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 void diagSort(vector<vector<int>>& mat,vector<vector<int>>& v,int r, int c,int m,int n)
    { priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=r,j=c;i<m && j<n;i++,j++)
        {
            pq.push(mat[i][j]);
            
        }
        int i=r,j=c;
        while(!pq.empty())
        {
            v[i++][j++]=pq.top();
            
            pq.pop();
        }
     return;
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
       
        vector<vector<int>> v(m, vector<int>(n));
        for(int i=n-1;i>0;i--)
        {
           diagSort(mat,v,0,i,m,n);
            
        }
        for(int i=0;i<m;i++)
        {
           diagSort(mat,v,i,0,m,n);
            
        }
        return v;
    }
int main()
{
   int m,n;
   cin>>m>>n;
   vector<vector<int>> mat(m, vector<int>(n));
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)

        {cin>>mat[i][j];
    
            }   
       
   }
   vector<vector<int>>res=diagonalSort(mat);
   for(auto i:res)
   {
       for(auto j:i)
       cout<<j<<"\t";
       cout<<endl;
   }

    return 0;
}
