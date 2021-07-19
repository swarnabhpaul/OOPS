#include<iostream>
#include<stdbool.h>
using namespace std;
class stack
{
private:
    int top, size;
    int *a;
    bool isempty();
    bool isfull();
    void initialize(int);
    void deconstruct();
public:
    stack(int);
    stack(int,int);
    stack();
    ~stack();
    void push(int);
    int pop();
    void display();
};
void stack::push(int x)
{
    if(isfull())
    {
        cout<<"Stack overflow!!\n";
        return;
    }
    top++;
    a[top]=x;
}
int stack::pop()
{
    if(isempty())
    {
        cout<<"Stack underflow!!\n";
        return -1;
    }
    int x=a[top];
    top--;
    return x;
}
stack::stack(int n)
{
    initialize(n);
    cout<<"Constructed stack of size "<<n<<endl;
}
stack::stack(int n,int x)
{
    initialize(n);
    cout<<"Constructed stack of size "<<n<<endl;
    top++;
    a[top]=x;
}
stack::stack()
{
    int n=10;
    initialize(n);
    cout<<"Constructed stack of size "<<n<<endl;
}
stack::~stack()
{
    deconstruct();
    cout<<"Destroyed stack of size "<<size<<endl;
}
void stack::display()
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
bool stack::isempty()
{
    return (top==-1);
}
bool stack::isfull()
{
    return (top==(size-1));
}
void stack::initialize(int n)
{
    a=new int[n];
    top=-1;
    size=n;
}
void stack::deconstruct()
{
    delete []a;
}
int main(void)
{
     stack s1(2);
     stack s2[2]={4,7};
     stack s3[3]={{2,20},{5,89},{3,5}};
     s3[1].display();
     s1.push(10);
     s1.push(20);
     s1.display();
     {
        stack *p=new stack(3,7);
        stack *q=new stack[4];
        (*p).push(10);
        p->display();
        delete []q;
        delete p;

     }

     s1.push(30);
     cout<<s1.pop()<<" "<<s1.pop()<<endl;
     s1.pop();
     return 0;
}
