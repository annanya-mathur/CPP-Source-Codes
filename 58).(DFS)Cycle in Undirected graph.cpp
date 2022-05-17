#include <iostream>
#include<vector>
using namespace std;

bool cycledfs(vector<int>adj[], int i,int p,vector<int>&visited)
{
    visited[i]=1;
    for(auto x:adj[i])
    {
        if(!visited[x])
        {
            if(cycledfs(adj,x,i,visited)) return true;
        }
        else 
        if( p!=x)
        return true;
        
    }
    return false;
}
int main() {
    int e,v,flag=0;
    cin>>e>>v;
	vector<int>adj[v+1];
	vector<int>visited(v+1,0);
	for(int i=0;i<e;i++)
	{
	    int x,y;
	    cin>>x>>y;
	    adj[x].push_back(y);
	    adj[y].push_back(x);
	}
	for(int i=1;i<=v;i++)
	{
	    if(!visited[i])
	    {
	        if(cycledfs(adj,i,-1,visited))
	        {flag=1;
	        break;}
	    }
	}
	if(flag)
	cout<<"Cycle is present"<<endl;
	else
	cout<<"Cycle is not present"<<endl;
	return 0;
}
