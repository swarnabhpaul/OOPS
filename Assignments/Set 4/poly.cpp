#include<iostream>
#include<stdbool.h>
#include<math.h>
using namespace std;
class node
{
public:
    int exp, coeff;
    node *link;
    node(int,int,node*);
};
node::node(int c=0,int e=0,node *l=NULL)
{
    coeff=c;
    exp=e;
    link=l;
}
class polynomial
{
    node head;
    bool isempty();
    node *createNewNode(int,int,node*);
public:
    polynomial(node*);
    polynomial(const polynomial&);
    ~polynomial();
    void DeletePoly();
    void InsertTerm(int,int);
    void DeleteTerm(int,int);
    void DisplayPoly();
    double EvalPoly(double);
    polynomial* AddPoly(const polynomial &p);
};
bool polynomial::isempty()
{
    return (head.coeff==0);
}
node* polynomial::createNewNode(int c,int e,node *l)
{
    node *t=new node(c,e,l);
    return t;
}
polynomial::polynomial(node *l=NULL)
{
    head.coeff=0;
    head.exp=0;
    head.link=l;
    if(l!=NULL)
    {
        int cnt=0, Max=l->exp;
        node *t=l;
        while(t=NULL)
        {
            t=t->link;
            cnt++;
            if(t->exp>Max)
                Max=t->exp;
        }
        head.coeff=cnt;
        head.exp=Max;
    }
    cout<<"Polynomial constructed"<<endl;
}
polynomial::polynomial(const polynomial &p)
{
    head.coeff=p.head.coeff;
    head.exp=p.head.exp;
    head.link=NULL;
    node *t=p.head.link;
    if(t!=NULL)
    {
        head.link=createNewNode(t->coeff,t->exp,head.link);
        t=t->link;
        node *q=head.link;
        for(int i=1;i<p.head.coeff;i++,q=q->link,t=t->link)
            q->link=createNewNode(t->coeff,t->exp,NULL);
    }
}
polynomial::~polynomial()
{
    DeletePoly();
    cout<<"Polynomial destroyed"<<endl;
}
void polynomial::DeletePoly()
{
    node *t;
    for(int i=0;i<head.coeff;i++)
    {
        t=head.link;
        head.link=head.link->link;
        delete t;
    }
    head.coeff=0;
}
void polynomial::InsertTerm(int c,int e)
{
    if(isempty())
    {
        head.link=createNewNode(c,e,head.link);
    }
    else if(head.link->exp>e)
    {
        head.link=createNewNode(c,e,head.link);
    }
    else
    {
        node *p=head.link;
        while(p->link!=NULL&&p->link->exp<e)
            p=p->link;
        p->link=createNewNode(c,e,p->link);
    }
    head.coeff++;
}
void polynomial::DeleteTerm(int c,int e)
{
    if(isempty())
    {
        cout<<"Polynomial is empty\n";
        return;
    }
    node *p=head.link;
    node *q;
    if(p->coeff==c&&p->exp==e)
    {
        head.link=p->link;
        delete p;
        head.coeff--;
    }
    else
    {
        while(p!=NULL&&(p->coeff!=c||p->exp!=e))
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
            head.coeff--;
        }
    }
}
void polynomial::DisplayPoly()
{
    if(head.coeff==0)
    {
        cout<<0<<endl;
        return;
    }
    node *t=head.link;
    cout<<t->coeff<<"x^"<<t->exp;
    t=t->link;
    for(int i=1;i<head.coeff;i++,t=t->link)
    {
        if(t->coeff>=0)
            cout<<"+";;
        cout<<t->coeff<<"x^"<<t->exp;
    }
    cout<<endl;
}
double polynomial::EvalPoly(double x)
{
    double result=0.0;
    node *t=head.link;
    for(int i=0;i<head.coeff;i++,t=t->link)
        result+=((t->coeff)*pow(x,t->exp));
    return result;
}
polynomial* polynomial::AddPoly(const polynomial &p)
{
    int i=0;
    polynomial *t=new polynomial;
    node *a=head.link;
    node *b=p.head.link;
    node *c;
    t->head.coeff=0;
    t->head.exp=0;
    t->head.link=NULL;
    while(a!=NULL&&b!=NULL)
    {
        if(a->exp<b->exp)
        {
            if(t->head.coeff==0)
            {
                t->head.link=createNewNode(a->coeff,a->exp,t->head.link);
                c=t->head.link;
            }
            else
            {
                c->link=createNewNode(a->coeff,a->exp,c->link);
                c=c->link;
            }
            (t->head.coeff)++;
            a=a->link;
        }
        else if(a->exp>b->exp)
        {
            if(t->head.coeff==0)
            {
                t->head.link=createNewNode(b->coeff,b->exp,t->head.link);
                c=t->head.link;
            }
            else
            {
                c->link=createNewNode(b->coeff,b->exp,c->link);
                c=c->link;
            }
            (t->head.coeff)++;
            b=b->link;
        }
        else
        {
            if(t->head.coeff==0)
            {
                t->head.link=createNewNode(a->coeff+b->coeff,a->exp,t->head.link);
                c=t->head.link;
            }
            else
            {
                c->link=createNewNode(a->coeff+b->coeff,a->exp,c->link);
                c=c->link;
            }
            (t->head.coeff)++;
            a=a->link;
            b=b->link;
        }
    }
    while(a!=NULL)
    {
        if(t->head.coeff==0)
        {
            t->head.link=createNewNode(a->coeff,a->exp,t->head.link);
            c=t->head.link;
        }
        else
        {
            c->link=createNewNode(a->coeff,a->exp,c->link);
            c=c->link;
        }
        (t->head.coeff)++;
        a=a->link;
    }
    while(b!=NULL)
    {
        if(t->head.coeff==0)
        {
            t->head.link=createNewNode(b->coeff,b->exp,t->head.link);
            c=t->head.link;
        }
        else
        {
            c->link=createNewNode(b->coeff,b->exp,c->link);
            c=c->link;
        }
        (t->head.coeff)++;
        b=b->link;
    }
    return t;
}
int main()
{
    polynomial p;
    p.InsertTerm(-4,3);
    p.InsertTerm(2,2);
    p.InsertTerm(6,0);
    p.InsertTerm(-7,1);
    p.DisplayPoly();
    polynomial q=p;
    p.DeleteTerm(6,0);
    p.DisplayPoly();
    q.DisplayPoly();
    cout<<q.EvalPoly(-2.5)<<endl;
    polynomial a,b;
    a.InsertTerm(5,0);
    a.InsertTerm(-1,1);
    a.InsertTerm(1,2);
    a.InsertTerm(4,3);
    cout<<"a = ";
    a.DisplayPoly();
    b.InsertTerm(2,1);
    b.InsertTerm(6,2);
    b.InsertTerm(-10,0);
    cout<<"b = ";
    b.DisplayPoly();
    polynomial *t=b.AddPoly(a);
    cout<<"a+b = ";
    t->DisplayPoly();
    delete t;
    return 0;
}
