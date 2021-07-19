#include<iostream>
#include<stdbool.h>
#include"MyLinkedList.h"
#include"MyHash.h"
using namespace std;
class Set
{
    hashing s;
public:
    Set(int);
    Set(const Set&);
    ~Set();
    Set operator + (const Set&);
    Set operator - (const Set&);
    Set operator * (const Set&);
    bool operator < (const Set&);
    bool operator <= (const Set&);
    bool operator > (const Set&);
    bool operator >= (const Set&);
    bool operator == (const Set&);
    bool operator != (const Set&);
    void operator = (const Set&);
    friend ostream& operator << (ostream&,const Set&);
    friend istream& operator >> (istream&,Set&);
};
Set::Set(int n=10): s(n)
{
}
Set::Set(const Set &t): s(t.s)
{
}
Set::~Set()
{
}
Set Set::operator + (const Set &t)
{
    Set res;
    for(int i=0;i<s.htsize;i++)
    {
        node *t1=s.ht[i].head.link;
        for(int j=0;j<s.ht[i].head.data;j++,t1=t1->link)
            res.s.Insert(t1->data);
    }
    for(int i=0;i<t.s.htsize;i++)
    {
        node *t1=t.s.ht[i].head.link;
        for(int j=0;j<t.s.ht[i].head.data;j++,t1=t1->link)
            if(!res.s.Search(t1->data))
                res.s.Insert(t1->data);
    }
    return res;
}
Set Set::operator - (const Set &t)
{
    Set res;
    for(int i=0;i<s.htsize;i++)
    {
        node *t1=s.ht[i].head.link;
        for(int j=0;j<s.ht[i].head.data;j++,t1=t1->link)
            if(!t.s.Search(t1->data))
                res.s.Insert(t1->data);
    }
    return res;
}
Set Set::operator * (const Set &t)
{
    Set res;
    for(int i=0;i<s.htsize;i++)
    {
        node *t1=s.ht[i].head.link;
        for(int j=0;j<s.ht[i].head.data;j++,t1=t1->link)
            if(t.s.Search(t1->data))
                res.s.Insert(t1->data);
    }
    return res;
}
bool Set::operator < (const Set &t)
{
    int size1=0, size2=0;
    for(int i=0;i<s.htsize;i++)
        size1+=s.ht[i].head.data;
    for(int i=0;i<t.s.htsize;i++)
        size2+=t.s.ht[i].head.data;
    if(size1>=size2)
        return false;
    for(int i=0;i<s.htsize;i++)
    {
        node *t1=s.ht[i].head.link;
        for(int j=0;j<s.ht[i].head.data;j++,t1=t1->link)
            if(!t.s.Search(t1->data))
                return false;
    }
    return true;
}
bool Set::operator <= (const Set &t)
{
    for(int i=0;i<s.htsize;i++)
    {
        node *t1=s.ht[i].head.link;
        for(int j=0;j<s.ht[i].head.data;j++,t1=t1->link)
            if(!t.s.Search(t1->data))
                return false;
    }
    return true;
}
bool Set::operator > (const Set &t)
{
    int size1=0, size2=0;
    for(int i=0;i<s.htsize;i++)
        size1+=s.ht[i].head.data;
    for(int i=0;i<t.s.htsize;i++)
        size2+=t.s.ht[i].head.data;
    if(size1<=size2)
        return false;
    for(int i=0;i<t.s.htsize;i++)
    {
        node *t1=t.s.ht[i].head.link;
        for(int j=0;j<t.s.ht[i].head.data;j++,t1=t1->link)
            if(!s.Search(t1->data))
                return false;
    }
    return true;
}
bool Set::operator >= (const Set &t)
{
    for(int i=0;i<t.s.htsize;i++)
    {
        node *t1=t.s.ht[i].head.link;
        for(int j=0;j<t.s.ht[i].head.data;j++,t1=t1->link)
            if(!s.Search(t1->data))
                return false;
    }
    return true;
}
bool Set::operator == (const Set &t)
{
    int size1=0, size2=0;
    for(int i=0;i<s.htsize;i++)
        size1+=s.ht[i].head.data;
    for(int i=0;i<t.s.htsize;i++)
        size2+=t.s.ht[i].head.data;
    if(size1!=size2)
        return false;
    for(int i=0;i<s.htsize;i++)
    {
        node *t1=s.ht[i].head.link;
        for(int j=0;j<s.ht[i].head.data;j++,t1=t1->link)
            if(!t.s.Search(t1->data))
                return false;
    }
    return true;
}
bool Set::operator != (const Set &t)
{
    return !((*this)==t);
}
void Set::operator = (const Set &t)
{
    for(int i=0;i<s.htsize;i++)
        s.ht[i].deletesll();
    for(int i=0;i<t.s.htsize;i++)
    {
        node *t1=t.s.ht[i].head.link;
        for(int j=0;j<t.s.ht[i].head.data;j++,t1=t1->link)
            s.Insert(t1->data);
    }
}
ostream& operator << (ostream &f,const Set &t)
{
    f<<"{ ";
    for(int i=0;i<t.s.htsize;i++)
    {
        node *t1=t.s.ht[i].head.link;
        for(int j=0;j<t.s.ht[i].head.data;j++,t1=t1->link)
            f<<t1->data<<" ";
    }
    f<<"}";
    return f;
}
istream& operator >> (istream &f,Set &t)
{
    int x;
    f>>x;
    if(!t.s.Search(x))
        t.s.Insert(x);
    return f;
}
int main()
{
    int n;
    Set s1, s2;
    cout<<"For s1:\n";
    cout<<"Input no: of elements: ";
    cin>>n;
    cout<<"Input elements: ";
    for(int i=0;i<n;i++)
        cin>>s1;
    cout<<"For s2:\n";
    cout<<"Input no: of elements: ";
    cin>>n;
    cout<<"Input elements: ";
    for(int i=0;i<n;i++)
        cin>>s2;
    Set s3(s1);
    cout<<"Displaying sets:\n";
    cout<<s1<<endl<<s2<<endl<<s3<<endl<<s1+s2<<endl<<s1-s2<<endl<<s1*s2<<endl;
    s3=s1+s2;
    cout<<s3<<endl;
    Set s4, s5;
    cout<<"For s4:\n";
    cout<<"Input no: of elements: ";
    cin>>n;
    cout<<"Input elements: ";
    for(int i=0;i<n;i++)
        cin>>s4;
    cout<<"For s5:\n";
    cout<<"Input no: of elements: ";
    cin>>n;
    cout<<"Input elements: ";
    for(int i=0;i<n;i++)
        cin>>s5;
    cout<<"Displaying sets:\n";
    cout<<s4<<endl<<s5<<endl;
    if(s4<s5)
        cout<<"s4 is a proper subset of s5"<<endl;
    if(s4<=s5)
        cout<<"s4 is a subset of s5"<<endl;
    if(s4>s5)
        cout<<"s4 is a proper superset of s5"<<endl;
    if(s4>=s5)
        cout<<"s4 is a superset of s5"<<endl;
    if(s4==s5)
        cout<<"They are equal"<<endl;
    if(s4!=s5)
        cout<<"They are not equal"<<endl;
    return 0;
}
