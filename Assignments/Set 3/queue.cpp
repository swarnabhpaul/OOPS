#include<iostream>
#include<stdbool.h>
using namespace std;
class queue
{
private:
    int size, front, rear;
    int *a;
    bool isempty();
    bool isfull();
    void initialize(int);
    void deconstruct();
public:
    void push(int);
    int pop();
    void display();
    queue(int,int);
    queue(int);
    queue();
    ~queue();
};
bool queue::isempty()
{
    return (rear==-1);
}
bool queue::isfull()
{
    return (((rear+1)%size==front)&&(rear!=-1));
}
void queue::push(int x)
{
    if(isfull())
    {
        cout<<"Queue overflow!!\n";
        return;
    }
    rear=(rear+1)%size;
    a[rear]=x;
}
int queue::pop()
{
    if(isempty())
    {
        cout<<"Queue underflow!!\n";
        return -1;
    }
    int x=a[front];
    if(front==rear)
    {
        front=0;
        rear=-1;
    }
    else
    {
        front=(front+1)%size;
    }
    return x;
}
void queue::display()
{
    if(isempty())
    {
        cout<<"Queue is empty\n";
        return;
    }
    int i;
    cout<<"Displaying queue: ";
    if(front<=rear)
    {
        for(i=front;i<=rear;i++)
            cout<<a[i]<<' ';
    }
    else
    {
        for(i=front;i<size;i++)
            cout<<a[i]<<' ';
        for(i=0;i<=rear;i++)
            cout<<a[i]<<' ';
    }
    cout<<endl;
}
queue::queue(int n)
{
    initialize(n);
    cout<<"Constructed queue of size "<<n<<endl;
}
queue::queue(int n,int x)
{
    initialize(n);
    cout<<"Constructed queue of size "<<n<<endl;
    rear++;
    a[rear]=x;
}
queue::queue()
{
    int n=10;
    initialize(n);
    cout<<"Constructed queue of size "<<n<<endl;
}
queue::~queue()
{
    deconstruct();
    cout<<"Destroyed queue of size "<<size<<endl;
}
void queue::initialize(int n)
{
    a=new int[n];
    size=n;
    front=0;
    rear=-1;
}
void queue::deconstruct()
{
    delete []a;
}
int main(void)
{
     queue s1(2);
     queue s2[2]={4,7};
     queue s3[3]={{2,20},{5,89},{3,5}};
     s3[1].display();
     s1.push(10);
     s1.push(20);
     s1.display();
     {
        queue *p=new queue(3,7);
        queue *q=new queue[4];
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
