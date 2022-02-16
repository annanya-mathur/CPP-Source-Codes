#include <iostream>
#include <climits>
using namespace std;
struct Node
{
    int data;
    Node* left ,*right;
    Node(int x)
    {
        data=x;
        left=right=NULL;
    }
};
Node* BSTpreorder(int arr[],int n,int &i,int max,int min,int value)
{ if(i>=n)
return NULL;
Node *root=NULL;
    if(value<max && value>min)
    {
        root=new Node(value);
        //cout<<"%"<<value<<"\t" <<max <<"\t"<<min<<endl;
        i++;
        if(i<n)
            root->left=BSTpreorder(arr,n,i,value,min,arr[i]);
        if(i<n)    
            root->right=BSTpreorder(arr,n,i,max,value,arr[i]);
        

    }
    return root;
}
void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<"\t";
        preorder(root->left);
        preorder(root->right);
    }
    return ;
}
int main()
{  int n,i=0;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   
   Node* root=BSTpreorder(arr,n,i,INT_MAX,INT_MIN,arr[0]);
   preorder(root);
    return 0;
}

