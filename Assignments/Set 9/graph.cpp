#include<iostream>
#include<stdbool.h>
#include"MyLinkedList.h"
#include"MyStack.h"
using namespace std;
class graph
{
    sll *adjl;
    int N;
public:
    graph(int);
    ~graph();
    void DFS();
    void Display();
    void connected_components();
    void insert_edge(int,int);
    void delete_edge(int,int);
};
graph::graph(int n)
{
    cout<<"Graph created"<<endl;
    N=n;
    adjl=new sll[N];
}
graph::~graph()
{
    int i;
    for(i=0;i<N;i++)
        adjl[i].deletesll();
    delete []adjl;
    cout<<"Graph destroyed"<<endl;
}
void graph::Display()
{
    int i;
    for(i=0;i<N;i++)
    {
        cout<<i+1<<": ";
        adjl[i].display();
    }
}
void graph::insert_edge(int u,int v)
{
    adjl[u-1].insertBeg(v);
}
void graph::delete_edge(int u,int v)
{
    if(!adjl[u-1].search(v))
    {
        cout<<"Error! Edge not present!"<<endl;
    }
    else
    {
        adjl[u-1].Delete(v);
    }
}
void graph::DFS()
{
    int i, cnt=0, u, j;
    node *t;
    for(i=0;i<N;i++)
        cnt+=adjl[i].head.data;
    stack s(cnt+N);
    for(i=0;i<N;i++)
        adjl[i].head.extra=0;
    for(i=0;i<N;i++)
    {
        if(!adjl[i].head.extra)
        {
            s.push(i+1);
            while(!s.isempty())
            {
                u=s.pop();
                if(!adjl[u-1].head.extra)
                {
                    cout<<u<<' ';
                    adjl[u-1].head.extra=1;
                }
                for(t=adjl[u-1].head.link,j=0;j<adjl[u-1].size();j++,t=t->link)
                    if(!adjl[t->data-1].head.extra)
                        s.push(t->data);
            }
        }
    }
}
void graph::connected_components()
{
    int i, cnt=0, u, j, n;
    node *t;
    for(i=0;i<N;i++)
        cnt+=adjl[i].head.data;
    stack s(cnt+N);
    for(i=0;i<N;i++)
        adjl[i].head.extra=0;
    cnt=0;
    for(i=0;i<N;i++)
    {
        if(!adjl[i].head.extra)
        {
            cnt++;
            n=0;
            cout<<"Connected component "<<cnt<<": ";
            s.push(i+1);
            while(!s.isempty())
            {
                u=s.pop();
                if(!adjl[u-1].head.extra)
                {
                    n++;
                    cout<<u<<' ';
                    adjl[u-1].head.extra=1;
                }
                for(t=adjl[u-1].head.link,j=0;j<adjl[u-1].size();j++,t=t->link)
                    if(!adjl[t->data-1].head.extra)
                        s.push(t->data);
            }
            cout<<"[ Size: "<<n<<" ]";
            cout<<endl;
        }
    }
    cout<<"Number of connected components: "<<cnt<<endl;
}
int main()
{
    int n, u, v;
    char ch;
    cout<<"How many vertices?: ";
    cin>>n;
    graph g1(n);
    cout<<"Want to enter edge? <y/n>: ";
    cin>>ch;
    while(ch=='y'||ch=='Y')
    {
        cout<<"Enter edge: ";
        cin>>u>>v;
        g1.insert_edge(u,v);
        if(u!=v)
            g1.insert_edge(v,u);
        cout<<"Want to enter more edges? <y/n>: ";
        cin>>ch;
    }
    cout<<"Displaying adjacency lists for each vertex:"<<endl;
    g1.Display();
    cout<<"DFS traversal: ";
    g1.DFS();
    cout<<endl;
    g1.connected_components();
    return 0;
}
