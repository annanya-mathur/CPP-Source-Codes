#include<bits/stdc++.h>
using namespace std;
int segmentTree[10000000];
void tree(vector<int>a,int start,int end,int index)
{ 
  if(start==end)
  {
    segmentTree[index]=a[start];
    return;
  }
  int mid=(start+end)/2;
  tree(a,start,mid,2*index+1);
  tree(a,mid+1,end,2*index+2);
  segmentTree[index]=(segmentTree[2*index+1])^(segmentTree[2*index+2]);
  
}
void update(int i,int index,int val,int newv,int start,int end)
{
    if(i<start||i>end)
    return;
    segmentTree[index]=(segmentTree[index])^val;
    segmentTree[index]=segmentTree[index]^newv;
    if(start<end)
    {
        int mid=(start+end)/2;
        update(i,2*index+1,val,newv,start,mid);
        update(i,2*index+2,val,newv,mid+1,end);
        
    }
    
}
vector<int> calcXOR (int n, vector<int> a, int q, vector<vector<int> > queries) {
   
   
   tree(a,0,n-1,0);
   int y=(int)(ceil(log2(n)));
   int s=(2*(int)pow(2,y))-1;
   
   cout<<endl;
   vector<int>r;
   for(int i=0;i<q;i++)
   {  int x=queries[i][0]-1;
       update(x,0,a[x],queries[i][1],0,n-1);
       a[x]=queries[i][1];
     
       r.push_back(segmentTree[0]);
   }
   if(q==0)
   r.push_back(segmentTree[0]);
   
   return r;
   
}

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            int p;
            cin>>p;
            a[i]=p;
            //cout<<p<<"\t";
        }
        
        int q;
        cin>>q;
        vector<vector<int>>v;
        for(int i=0;i<q;i++)
        { vector<int>z;
            for(int j=0;j<2;j++)
            {  int p;
            cin>>p;
            
            z.push_back(p);
            }
            v.push_back(z);
        }
        
        vector<int>r=calcXOR(n,a,q,v);
        
        for(int i=0;i<q;i++)
        {
            cout<<r[i]<<" ";
        }
        cout<<endl;
    }
}

