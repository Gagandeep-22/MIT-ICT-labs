#include<iostream>
using namespace std;
#define MAX 1000
class Stack
{
public:
    int top;
    int a[MAX];
    Stack()
    {
        top=-1;
    }
public:
    void push(int);
    void pop();
    void peek();
    void isEmpty();
    void display();
};
void Stack::push(int x)
{
    if(top>=(MAX - 1))
    {
        cout<<"Stack Overflow";
    }
    else
    {
        a[++top]=x;
        cout<<x<<" is pushed into stack\n";
    }
}
void Stack::pop()
{
    if(top<0)
    {
        cout<<"Stack Underflow";
    }
    else
    {
        int x=a[top];
        top--;
        cout<<x<<" is popped from the stack\n";

    }
}
    void Stack::peek()
    {

            if(top<0)
            {
                cout<<"Stack is empty";
            }
            else
            {
                int x=a[top];
                cout<<"the top element of stack is "<<x<<"\n";
            }

    }
    void Stack::isEmpty()
    {
        if(top<0)
        {
            cout<<"the stack is empty\n";
        }
        else
        {
            cout<<"The stack contains elements\n";
        }
    }
    void Stack::display()
    {
        if(top>=0)
        {
            cout<<"\nStack element are: \n";
            for(int i=top;i>=0;i--)
                cout<<a[i]<<" ";
        }
        else
            cout<<"Stack is empty";
    }
int main()
{

    Stack s;
    int flag=1, n, ch,n2;
    while(flag == 1)
    {
        cout<<"Enter the element: \n";
        cin>>n;
        s.push(n);
        cout<<"Do u want to enter again: (1 for Yes, 0 for no) \n";
        cin>>ch;
        if(ch==0)
            flag=0;
    }
    cout<<"How many  elements u want to pop: \n";
    cin>>n2;
    for(int i=0;i<n2;i++)
        s.pop();
    s.display();
    s.peek();
    s.isEmpty();
}
