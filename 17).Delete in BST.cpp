#include<bits/stdc++.h>

using namespace std;
struct tree
{
    int data;
    tree *right , *left;
    tree(int x)
    {
       data=x;
       right=left=NULL;
    }
};

tree *getsucessor(tree *root)
{
    root=root->right;
    while(root!=NULL &&root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
tree *delete_key(tree*root,int key)
{
    if(root==NULL) 
return root;
    if(key<root->data)
    delete_key(root->left,key);
   else if (key>root->data)
    delete_key(root->right,key);
    else
    {   
        if(root->left==NULL )
        {
            tree* temp=root->right;
            delete(root);
            return temp;
            
        }
       else  if(root->right==NULL )
        {
            tree* temp=root->left;
            delete(root);
            return temp;
        }
        else
        {tree* curr=getsucessor(root);
        root->data=curr->data;
        root->right=delete_key(root->right,curr->data);}
        return root;
    }
    
}
void preorder(tree *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<"\t";
        preorder(root->left);
        preorder(root->right);
    }
    return;
}
tree *constructBST(tree *root,int bst[],int start,int end)
{   if(start>end)
    return NULL;
    int mid=(start+end)/2;
    root=new tree(bst[mid]);
   
    root->left=constructBST(root,bst,start,mid-1);
    root->right=constructBST(root,bst,mid+1,end);
    return root;
}

int main()
{
    int n;
    cin>>n;
    int bst[n];
    for(int i=0;i<=n;i++)
    {
        cin>>bst[i];
        
    }
    sort(bst,bst+n);
    tree* root;
    root=constructBST(root,bst,0,n-1);
    preorder(root);
    cout<<endl;
    delete_key(root,80);
    
    preorder(root);
    cout<<endl;
    return 0;
}
