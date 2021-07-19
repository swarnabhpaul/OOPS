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
    bool isempty();
public:
    node* createNewNode(int,node*);
    node head;
    sll(node *l);
    sll(const sll&);
    ~sll();
    void deletesll();
    void insertBeg(int);
    void Delete(int);
    bool search(int);
    void display();
    int size();
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
    cout<<"List constructed"<<endl;
}
sll::sll(const sll &s)
{
    head.data=s.head.data;
    head.link=NULL;
    node *t=s.head.link;
    if(t!=NULL)
    {
        insertBeg(t->data);
        head.data--;
        t=t->link;
        node *p=head.link;
        for(int i=1;i<s.head.data;i++,t=t->link,p=p->link)
            p->link=createNewNode(t->data,NULL);
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
bool sll::isempty()
{
    return (head.data==0);
}
void sll::insertBeg(int x)
{
    head.link=createNewNode(x,head.link);
    head.data++;
}
node* sll::createNewNode(int x,node *l)
{
    node *t=new node(x,l);
    return t;
}
sll::~sll()
{
    deletesll();
    cout<<"List destroyed"<<endl;
}
void sll::Delete(int x)
{
    if(isempty())
    {
        cout<<"List is empty\n";
        return;
    }
    node *p=head.link;
    node *q;
    if(p->data==x)
    {
        head.link=p->link;
        delete p;
        head.data--;
    }
    else
    {
        while(p!=NULL&&p->data!=x)
        {
            q=p;
            p=p->link;
        }
        if(p==NULL)
            cout<<"No match :: deletion failed\n";
        else
        {
            q->link=p->link;
            delete p;
            head.data--;
        }
    }
}
bool sll::search(int x)
{
    node *t=head.link;
    int i;
    for(i=0;i<head.data;i++,t=t->link)
        if(t->data==x)
            return true;
    return false;
}
void sll::display()
{
    node *t=head.link;
    for(int i=0;i<head.data;i++,t=t->link)
    {
        cout<<t->data<<" --> ";
    }
    cout<<"||"<<endl;
}
int sll::size()
{
    return head.data;
}
