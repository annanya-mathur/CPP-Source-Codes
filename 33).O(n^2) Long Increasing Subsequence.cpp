#include <iostream>

using namespace std;

void longestIncSub(int arr[],int n)
{
    int lis[n],len=1;
    lis[0]=1;
    for(int i=1;i<n;i++)
    {lis[i]=1;
       for(int j=0;j<i;j++)
       {
           if(arr[i]>arr[j])
           {lis[i]=max(lis[i],lis[j]+1);
           len++;}
       }
    }
    cout<<"LENGTH OF LONGEST INCREASING SUBSEQUENCE"<<"\t";
    int res=lis[0];
    for(int i=1;i<n;i++)
    res=max(res,lis[i]);
    cout<<res;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   longestIncSub(arr,n);    

    return 0;
}

