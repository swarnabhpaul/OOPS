#include<iostream>
#include<stdbool.h>
using namespace std;
class node
{
public:
    int data;
    node *link;
    node(int,node*);
};
node::node(int x=0,node *l=NULL)
{
    data=x;
    link=l;
}
class sll
{
    node head;
    bool isempty();
public:
    sll(node*);
    sll(const sll&);
    ~sll();
    sll operator + (const sll&);
    void operator ! ();
    bool operator == (const sll&);
    void operator = (const sll&);
    node* operator [] (int);
    friend ostream& operator << (ostream&,const sll&);
    friend istream& operator >> (istream&,sll&);
    void deletesll();
    void* operator new (size_t);
    void* operator new [] (size_t);
    void operator delete (void*);
    void operator delete [] (void*);
};
sll::sll(node *l=NULL)
{
    head.data=0;
    head.link=l;
    if(l!=NULL)
    {
        int cnt=1;
        node *t=l;
        while(t->link!=NULL)
        {
            t=t->link;
            cnt++;
        }
        head.data=cnt;
    }
}
sll::sll(const sll &s)
{
    head.data=s.head.data;
    head.link=NULL;
    node *t=s.head.link;
    if(t!=NULL)
    {
        head.link=new node(t->data,head.link);
        t=t->link;
        node *p=head.link;
        for(int i=1;i<s.head.data;i++,t=t->link,p=p->link)
            p->link=new node(t->data,NULL);
    }
}
void sll::deletesll()
{
    node *t;
    for(int i=0;i<head.data;i++)
    {
        t=head.link;
        head.link=head.link->link;
        delete t;
    }
    head.data=0;
}
sll::~sll()
{
    deletesll();
}
sll sll::operator + (const sll &s)
{
    sll res;
    res.head.data=head.data+s.head.data;
    node *p=NULL, *t=NULL;
    if(head.data>0)
    {
        res.head.link=new node(head.link->data,res.head.link);
        p=res.head.link;
        t=head.link->link;
    }
    for(int i=1;i<head.data;i++)
    {
        p->link=new node(t->data,NULL);
        t=t->link;
        p=p->link;
    }
    int i=0;
    if(head.data==0&&s.head.data>0)
    {
        res.head.link=new node(s.head.link->data,res.head.link);
        p=res.head.link;
        t=s.head.link->link;
        i++;
    }
    else
        t=s.head.link;
    for(;i<s.head.data;i++)
    {
        p->link=new node(t->data,NULL);
        t=t->link;
        p=p->link;
    }
    return res;
}
void sll::operator ! ()
{
    if(head.data==0||head.data==1)
    {
        return;
    }
    node *prevnode=head.link, *curnode=head.link->link;
    head.link=head.link->link;
    prevnode->link=NULL;
    for(int i=1;i<head.data;i++)
    {
        head.link=head.link->link;
        curnode->link=prevnode;
        prevnode=curnode;
        curnode=head.link;
    }
    head.link=prevnode;
}
bool sll::operator == (const sll &s)
{
    if(head.data!=s.head.data)
        return false;
    node *t=head.link;
    node *p=s.head.link;
    for(int i=0;i<head.data;i++,t=t->link,p=p->link)
        if(t->data!=p->data)
            return false;
    return true;
}
void sll::operator = (const sll &s)
{
    deletesll();
    head.data=s.head.data;
    node *t=s.head.link;
    if(t!=NULL)
    {
        head.link=new node(t->data,head.link);
        t=t->link;
        node *p=head.link;
        for(int i=1;i<s.head.data;i++,t=t->link,p=p->link)
            p->link=new node(t->data,NULL);
    }
}
node* sll::operator [] (int index)
{
    if(index<0||index>=head.data)
    {
        cout<<"Index out of range"<<endl;
        return NULL;
    }
    node *t=head.link;
    for(int i=0;i<index;i++)
        t=t->link;
    return t;
}
ostream& operator << (ostream &f,const sll &s)
{
    node *t=s.head.link;
    for(int i=0;i<s.head.data;i++,t=t->link)
    {
        f<<t->data<<" --> ";
    }
    f<<"||";
    return f;
}
istream& operator >> (istream &f,sll &s)
{
    int x;
    f>>x;
    s.head.link=new node(x,s.head.link);
    s.head.data++;
    return f;
}
void* sll::operator new (size_t size)
{
    cout<<"Overloaded new with size "<<size<<endl;
    void *p=NULL;
    p=malloc(size);
    return p;
}
void* sll::operator new [] (size_t size)
{
    cout<<"Overloaded new [] with size "<<size<<endl;
    void *p=NULL;
    p=malloc(size);
    return p;
}
void sll::operator delete (void *p)
{
    cout<<"Overloaded delete"<<endl;
    free(p);
}
void sll::operator delete [] (void *p)
{
    cout<<"Overloaded delete []"<<endl;
    free(p);
}
int main()
{
    sll l1, l2;
    cout<<"Input list l1: ";
    for(int i=0;i<5;i++)
        cin>>l1;
    cout<<"Input list l2: ";
    for(int i=0;i<5;i++)
        cin>>l2;
    sll l3;
    l3=l1;
    sll l4(l2);
    if(l1==l2)
        cout<<"They are equal"<<endl;
    cout<<"Displaying lists:"<<endl;
    cout<<l1<<endl<<l2<<endl<<l3<<endl<<l4<<endl<<l1+l2<<endl;
    !l3;
    cout<<l3<<endl;
    int i;
    cout<<"Enter index for l3: ";
    cin>>i;
    node *t=l3[i];
    if(t!=NULL)
    {
        cout<<"Value at index "<<i<<" is: "<<t->data<<endl;
    }
    sll *lp;
    lp=new sll(l1);
    sll *lp2;
    lp2=new sll[3];
    for(int i=0;i<3;i++)
        lp2[i]=l2;
    cout<<"Displaying lists:"<<endl;
    cout<<(*lp)<<endl;
    for(int i=0;i<3;i++)
        cout<<lp2[i]<<endl;
    delete []lp2;
    delete lp;
    return 0;
}
