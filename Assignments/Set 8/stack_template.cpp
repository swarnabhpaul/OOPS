#include<iostream>
#include<stdbool.h>
using namespace std;
class stackOverflow
{
};
class stackUnderflow
{
};
template <class Z,int t=5>
class stack
{
private:
    int top, size;
    Z *a;
    bool isempty();
    bool isfull();
    void initialize(int);
    void deconstruct();
public:
    stack(int n=t);
    ~stack();
    void push(Z);
    Z pop();
    void display();
};
template <class Z,int t>
void stack<Z,t>::push(Z x)
{
    if(isfull())
    {
        throw stackOverflow();
    }
    top++;
    a[top]=x;
}
template <class Z,int t>
Z stack<Z,t>::pop()
{
    if(isempty())
    {
        throw stackUnderflow();
    }
    Z x=a[top];
    top--;
    return x;
}
template <class Z,int t>
stack<Z,t>::stack(int n)
{
    initialize(n);
    cout<<"Constructed stack of size "<<n<<endl;
}
template <class Z,int t>
stack<Z,t>::~stack()
{
    deconstruct();
    cout<<"Destroyed stack of size "<<size<<endl;
}
template <class Z,int t>
void stack<Z,t>::display()
{
    if(isempty())
    {
        cout<<"Stack is empty\n";
        return;
    }
    cout<<"Displaying stack from top to bottom:\n";
    for(int i=top;i>=0;i--)
        cout<<a[i]<<' ';
    cout<<endl;
}
template <class Z,int t>
bool stack<Z,t>::isempty()
{
    return (top==-1);
}
template <class Z,int t>
bool stack<Z,t>::isfull()
{
    return (top==(size-1));
}
template <class Z,int t>
void stack<Z,t>::initialize(int n)
{
    a=new Z[n];
    top=-1;
    size=n;
}
template <class Z,int t>
void stack<Z,t>::deconstruct()
{
    delete []a;
}
int main(void)
{
    stack<string,10> sch1(3);
    try
    {
        sch1.push("Alter");
        sch1.push("Deter");
        sch1.push("Glue");
        sch1.push("Critical");
    }
    catch(stackOverflow e)
    {
        cout<<"Stack overflow!"<<endl;
    }
    sch1.display();
    try
    {
        for(int i=0;i<4;i++)
            cout<<sch1.pop()<<' ';
        cout<<endl;
    }
    catch(stackUnderflow e)
    {
        cout<<"\nStack underflow!"<<endl;
    }
    return 0;
}
