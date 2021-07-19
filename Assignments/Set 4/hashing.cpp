#include<iostream>
#include<stdbool.h>
#include<math.h>
#include<time.h>
#include"MyLinkedList.h"
using namespace std;
class hashing
{
    sll *ht;
    int htsize;
    int hashfn(int);
public:
    hashing(int);
    hashing(const hashing&);
    ~hashing();
    bool Search(int);
    void Insert(int);
    void Delete(int);
    void Display();
    double TableLoadDistr();
};
hashing::hashing(const hashing &h)
{
    htsize=h.htsize;
    ht=new sll[htsize];
    for(int i=0;i<htsize;i++)
    {
        node *t=h.ht[i].head.link;
        ht[i].head.data=h.ht[i].head.data;
        if(t!=NULL)
        {
            ht[i].head.link=new node(t->data,ht[i].head.link);
            t=t->link;
            node *p=ht[i].head.link;
            for(int j=1;j<ht[i].head.data;j++,p=p->link,t=t->link)
                p->link=new node(t->data,NULL);
        }
    }
}
int hashing::hashfn(int x)
{
    return (x%htsize);
}
hashing::hashing(int n=10)
{
    ht=new sll[n];
    htsize=n;
}
hashing::~hashing()
{
    for(int i=0;i<htsize;i++)
        ht[i].deletesll();
    delete []ht;
}
bool hashing::Search(int x)
{
    int index=hashfn(x);
    return (ht[index].search(x));
}
void hashing::Insert(int x)
{
    int index=hashfn(x);
    ht[index].insertBeg(x);
}
void hashing::Delete(int x)
{
    int index=hashfn(x);
    if(Search(x))
    {
        ht[index].Delete(x);
    }
    else
        cout<<"Element not found. Deletion not possible."<<endl;
}
void hashing::Display()
{
    for(int i=0;i<htsize;i++)
        ht[i].display();
}
double hashing::TableLoadDistr()
{
    int totalElements=0;
    double deviation=0.0, expectedLoad=100.0/htsize, bucketLoad;
    for(int i=0;i<htsize;i++)
        totalElements+=ht[i].size();

    cout<<"Expected load in each bucket = "<<expectedLoad<<"%"<<endl;
    for(int i=0;i<htsize;i++)
    {
        bucketLoad=ht[i].size()*100.0/totalElements;
        cout<<"Load in bucket "<<i+1<<" = "<<bucketLoad<<"%"<<endl;
        deviation+=fabs(expectedLoad-bucketLoad);
    }
    return deviation;
}
unsigned long int myrand(unsigned long int x)
{
    unsigned long long int m=2147483647, a=65539;
    unsigned long int r=(x*a)%m;
    return r;
}
int main()
{
    hashing h1;
    double deviation1, deviation2;
    unsigned long int seed;
    int e;
    time_t seconds=time(NULL);
    seed=seconds;
    for(int i=0;i<100;i++)
    {
        seed=myrand(seed);
        h1.Insert(seed%100+1);
    }
    hashing h2(h1);
    cout<<"Displaying hash table:"<<endl;
    h1.Display();
    cout<<"Displaying hash table:"<<endl;
    h2.Display();
}
