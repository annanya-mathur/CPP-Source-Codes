#include <iostream>
#include <climits>
#define n 1000
using namespace std;
class Mystack
{
    private: int *stack;
             int top;
    public: 
    Mystack()
    {
        stack=new int[n];
        top=-1;
    }
    void push(int x)
    {   //cout<<top;
        if(top==n-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else
        top++;
        stack[top]=x;
        //cout<<"push: "<<stack[top]<<"\t";
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
        
    }
    bool empty()
    {
        if(top==-1)
        return true;
        else return false;
    }
    void display()
    {
        while(empty()==false)
        {
            cout<<stack[top]<<endl;
            top--;
        }
    }
};

int main()
{   int size_s;
    cin>>size_s;
    
    int arr[size_s];
    Mystack st;
    for(int i=0;i<size_s;i++)
    {
        cin>>arr[i];
        st.push(arr[i]);
    }
    st.display();
    return 0;
}
