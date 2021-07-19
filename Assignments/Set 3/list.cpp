#include<iostream>
#include<stdbool.h>
#include<time.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
class list
{
private:
    node *head;
    void initialize();
    void deconstruct();
    bool isempty();
    node* createNewNode(int);
public:
    list();
    list(int);
    ~list();
    void insertBeg(int);
    void display();
    void Delete(int);
    bool search(int);
    void concatenate(list*);
};
void list::initialize()
{
    head=NULL;
}
void list::deconstruct()
{
    node *t=head;
    while(head!=NULL)
    {
        head=head->next;
        delete t;
        t=head;
    }
}
bool list::isempty()
{
    return head==NULL;
}
node* list::createNewNode(int x)
{
    node *t=new node;
    t->data=x;
    t->next=NULL;
    return t;
}
list::list()
{
    initialize();
    cout<<"List created\n";
}
list::list(int x)
{
    initialize();
    cout<<"List created\n";
    head=createNewNode(x);
}
void list::insertBeg(int x)
{
    node *t=createNewNode(x);
    if(t==NULL)
    {
        cout<<"Out of memory\n";
        return;
    }
    if(head==NULL)
        head=t;
    else
    {
        t->next=head;
        head=t;
    }
}
void list::display()
{
    if(isempty())
    {
        cout<<"List is empty\n";
        return;
    }
    cout<<"Displaying list from beginning:\n";
    for(node *t=head;t!=NULL;t=t->next)
        cout<<t->data<<' ';
    cout<<endl;
}
void list::Delete(int x)
{
    if(isempty())
    {
        cout<<"List is empty\n";
        return;
    }
    node *p=head;
    node *q;
    int val;
    if(head->data==x)
    {
        val=head->data;
        head=head->next;
        delete p;
        cout<<"Successfully deleted "<<val<<endl;
    }
    else
    {
        while(p!=NULL&&p->data!=x)
        {
            q=p;
            p=p->next;
        }
        if(p==NULL)
            cout<<"No match :: deletion failed\n";
        else
        {
            val=p->data;
            q->next=p->next;
            delete p;
            cout<<"Successfully deleted "<<val<<endl;
        }
    }
}
bool list::search(int x)
{
    for(node *t=head;t!=NULL;t=t->next)
        if(t->data==x)
            return true;
    return false;
}
void list::concatenate(list *l)
{

    if(head==NULL)
    {
        head=l->head;
        return;
    }
    else if(l->head==NULL)
    {
        l->head=head;
        return;
    }
    else
    {
        node *t;
        for(t=head;t->next!=NULL;t=t->next);
        t->next=l->head;
    }
}
list::~list()
{
    deconstruct();
    cout<<"List destroyed\n";
}
unsigned long int myrand(unsigned long int x)
{
    unsigned long long int m=2147483647, a=65539;
    unsigned long int r=(x*a)%m;
    return r;
}
int main()
{
    list l1(50), l2, l3[4]={1,2,3,4};
    time_t t=time(NULL);
    unsigned long int seed=t;
    int x;
    for(int i=0;i<10;i++)
    {
        seed=myrand(seed);
        l2.insertBeg(seed%100);
    }
    l2.display();
    cout<<"Enter element to be deleted: ";
    cin>>x;
    l2.Delete(x);
    l2.display();
    l1.display();
    {
        list *l4=new list(10);
        list *l5=new list[5];
        l4->insertBeg(5);
        l4->display();
        delete []l5;
        delete l4;
    }
    l3[2].display();
    return 0;
}
