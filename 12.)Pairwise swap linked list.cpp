#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
Node *head=NULL;
void construct_ll(int link[],int n)
{ Node *curr;
int i=0;
    while(i<n)
    {if(head==NULL)
    {
        head=new Node(link[i]);
        cout<<"Head: "<<head->data<<"\t";
        curr=head;
    }
    else
    {
        curr->next=new Node(link[i]);
        curr=curr->next;
        cout<<"new node: "<<curr->data<<"\t";
    }
    i++;
    }
    
}
void pairwise_swap()
{
    Node* prev=head;
    Node* curr=head->next->next;
    head=head->next;
    head->next=prev;
    while(curr!=NULL&&curr->next!=NULL)
    {
        prev->next=curr->next;
        prev=curr;
        Node *temp=curr->next->next;
        curr->next->next=curr;
        curr=temp;
        
    }
    prev->next=curr;
}
void display_ll()
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<"\t";
        curr=curr->next;
    }
}
int main()
{
    int n;
    cin>>n;
    int link[n];

    for(int i=0;i<n;i++)
    {cin>>link[i];
    }
    construct_ll(link,n);
    pairwise_swap();
    cout<<endl;
    display_ll();
    return 0;
}
