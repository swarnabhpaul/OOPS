using namespace std;
template <class Z,int E=0>
class node
{
public:
    Z data;
    int e;
    node *link;
    node(Z a,node *l=NULL);
    node();
};
template <class Z,int E>
node<Z,E>::node(Z x,node *l)
{
    data=x;
    link=l;
    e=E;
}
template <class Z,int E>
node<Z,E>::node()
{
    link=NULL;
    e=E;
}
template <class Z>
class sll
{
public:
    node<Z> head;
    node<Z>* createNewNode(Z,node<Z>*);
    bool isempty();
    sll(node<Z> *l=NULL);
    sll(const sll&);
    ~sll();
    void deletesll();
    void insertBeg(Z);
    void Delete(Z);
    bool search(Z);
    void display();
    int size();
};
template <class Z>
sll<Z>::sll(node<Z> *l)
{
    head.e=0;
    head.link=l;
    if(l!=NULL)
    {
        int cnt=1;
        node<Z> *t=l;
        while(t->link!=NULL)
        {
            t=t->link;
            cnt++;
        }
        head.e=cnt;
    }
}
template <class Z>
sll<Z>::sll(const sll &s)
{
    head.e=s.head.e;
    head.link=NULL;
    node<Z> *t=s.head.link;
    if(t!=NULL)
    {
        insertBeg(t->data);
        head.e--;
        t=t->link;
        node<Z> *p=head.link;
        for(int i=1;i<s.head.e;i++,t=t->link,p=p->link)
            p->link=createNewNode(t->data,NULL);
    }

}
template <class Z>
void sll<Z>::deletesll()
{
    node<Z> *t;
    for(int i=0;i<head.e;i++)
    {
        t=head.link;
        head.link=head.link->link;
        delete t;
    }
    head.e=0;
}
template <class Z>
bool sll<Z>::isempty()
{
    return (head.e==0);
}
template <class Z>
void sll<Z>::insertBeg(Z x)
{
    head.link=createNewNode(x,head.link);
    head.e++;
}
template <class Z>
node<Z>* sll<Z>::createNewNode(Z x,node<Z> *l)
{
    node<Z> *t=new node<Z>(x,l);
    return t;
}
template <class Z>
sll<Z>::~sll()
{
    deletesll();
}
template <class Z>
void sll<Z>::Delete(Z x)
{
    if(isempty())
    {
        cout<<"List is empty\n";
        return;
    }
    node<Z> *p=head.link;
    node<Z> *q;
    if(p->data==x)
    {
        head.link=p->link;
        delete p;
        head.e--;
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
            head.e--;
        }
    }
}
template <class Z>
bool sll<Z>::search(Z x)
{
    node<Z> *t=head.link;
    int i;
    for(i=0;i<head.e;i++,t=t->link)
        if(t->data==x)
            return true;
    return false;
}
template <class Z>
void sll<Z>::display()
{
    node<Z> *t=head.link;
    for(int i=0;i<head.e;i++,t=t->link)
    {
        cout<<t->data<<" --> ";
    }
    cout<<"||"<<endl;
}
template <class Z>
int sll<Z>::size()
{
    return head.e;
}
