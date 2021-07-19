#include<iostream>
#include<stdbool.h>
#include<math.h>
#include<fstream>
#include<sstream>
#include"MyLinkedListTemplate.h"
using namespace std;
class not_found_exception{};
template <class Z,int s=293>
class hashing
{
public:
    sll<Z> *ht;
    int htsize;
    int hashfn(int);
    int hashfn(string);
    hashing(int n=s);
    hashing(const hashing&);
    ~hashing();
    bool Search(Z);
    void Insert(Z);
    void Delete(Z);
    void Display();
    void TableLoadDistr();
    void SearchWithName(string);
};
template <class Z,int s>
hashing<Z,s>::hashing(const hashing &h)
{
    htsize=h.htsize;
    ht=new sll<Z>[htsize];
    for(int i=0;i<htsize;i++)
    {
        node<Z> *t=h.ht[i].head.link;
        ht[i].head.e=h.ht[i].head.e;
        if(t!=NULL)
        {
            ht[i].head.link=new node<Z>(t->data,ht[i].head.link);
            t=t->link;
            node<Z> *p=ht[i].head.link;
            for(int j=1;j<ht[i].head.e;j++,p=p->link,t=t->link)
                p->link=new node<Z>(t->data,NULL);
        }
    }
}
template <class Z,int s>
int hashing<Z,s>::hashfn(int x)
{
    return (abs(x)%htsize);
}
template <class Z,int s>
int hashing<Z,s>::hashfn(string s1)
{
    string str;
    stringstream sin(s1);
    for(int i=1;i<=4;i++)
        getline(sin,str,',');
    int n=str.length();
    int cnt=0;
    int m=htsize;
    for(int i=0;i<n;i++)
    {
        cnt+=((i%m)*(int(str[i])%htsize));
        cnt%=htsize;
    }
    return cnt;
}
template <class Z,int s>
hashing<Z,s>::hashing(int n)
{
    ht=new sll<Z>[n];
    htsize=n;
}
template <class Z,int s>
hashing<Z,s>::~hashing()
{
    for(int i=0;i<htsize;i++)
        ht[i].deletesll();
    delete []ht;
}
template <class Z,int s>
bool hashing<Z,s>::Search(Z x)
{
    int index=hashfn(x);
    return (ht[index].search(x));
}
template <class Z,int s>
void hashing<Z,s>::Insert(Z x)
{
    int index=hashfn(x);
    ht[index].insertBeg(x);
}
template <class Z,int s>
void hashing<Z,s>::Delete(Z x)
{
    int index=hashfn(x);
    if(Search(x))
    {
        ht[index].Delete(x);
    }
    else
    {
        throw not_found_exception();
    }
}
template <class Z,int s>
void hashing<Z,s>::Display()
{
    for(int i=0;i<htsize;i++)
        ht[i].display();
}
template <class Z,int s>
void hashing<Z,s>::TableLoadDistr()
{
    int totalElements=0;
    for(int i=0;i<htsize;i++)
        totalElements+=ht[i].size();
    double mean=double(totalElements)/htsize, standardDev;
    cout<<"Mean load in each bucket = "<<mean<<endl;
    for(int i=0;i<htsize;i++)
        standardDev+=((ht[i].size()-mean)*(ht[i].size()-mean));
    standardDev/=htsize;
    standardDev=sqrt(standardDev);
    cout<<"STD of the load = "<<standardDev<<endl;
}
template <class Z,int s>
void hashing<Z,s>::SearchWithName(string name)
{
    int n=name.length();
    int cnt=0;
    int m=htsize;
    bool found=false;
    for(int i=0;i<n;i++)
    {
        cnt+=((i%m)*(int(name[i])%htsize));
        cnt%=htsize;
    }
    string str, sname;
    struct node<Z> *nd=ht[cnt].head.link;
    for(int i=0;i<ht[cnt].size();i++,nd=nd->link)
    {
        str=nd->data;
        stringstream sin(str);
        for(int j=1;j<=4;j++)
            getline(sin,sname,',');
        if(name==sname)
        {
            cout<<"Record found. Record is:"<<endl;
            cout<<str<<endl;
            found=true;
            break;
        }
    }
    if(!found)
    {
        cout<<"Record not found."<<endl;
    }
}
int main()
{
    hashing<string> hstr;
    ifstream fin;
    fin.open("TENTATIVE 2nd Semester Roll Sheet  2020-2021.csv");
    string line,word;
    getline(fin,line);
    getline(fin,line);
    getline(fin,line);
    while(getline(fin,line))
    {
        hstr.Insert(line);
    }
    hstr.TableLoadDistr();
    fin.close();
    string name;
    cout<<"Enter name whose record is to be displayed: ";
    getline(cin,name);
    hstr.SearchWithName(name);
    return 0;
}
