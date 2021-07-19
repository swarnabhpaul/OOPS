#include<iostream>
#include<stdbool.h>
#include"MyLinkedList.h"
#include"MyStack.h"
using namespace std;
class Graph
{
    sll *g;
    int V;
    int minDist(int*,bool*);
public:
    Graph(int);
    ~Graph();
    Graph(const Graph&);
    void insertEdge(int,int);
    void deleteEdge(int,int);
    void displayGraph();
    void dfs();
    void connectedComponents();
    int shortestPath(int,int);
};
Graph::Graph(int n=10)
{
    V=n;
    g=new sll[n];
    cout<<"Graph constructed with "<<V<<" vertices"<<endl;
}
Graph::~Graph()
{
    for(int i=0;i<V;i++)
        g[i].deletesll();
    delete []g;
    cout<<"Graph with "<<V<<" vertices destroyed"<<endl;
}
void Graph::insertEdge(int u,int v)
{
    if(u<1||u>V||v<1||v>V)
    {
        cout<<"Wrong input. Insertion not possible."<<endl;
        return;
    }
    if(u!=v)
    {
        g[u-1].insertBeg(v);
        g[v-1].insertBeg(u);
    }
    else
    {
        g[u-1].insertBeg(v);
    }
}
void Graph::displayGraph()
{
    for(int i=0;i<V;i++)
    {
        cout<<"Adjacency list of vertex "<<i+1<<": ";
        g[i].display();
    }
}
void Graph::connectedComponents()
{
    stack s(V*V);
    int top;
    node *t;
    bool *visited=new bool[V];
    int cnt=0, N=0;
    for(int i=0;i<V;i++)
        visited[i]=false;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            cnt++;
            N=0;
            s.push(i+1);
            cout<<"Connected component "<<cnt<<": ";
            while(!s.isempty())
            {
                top=s.pop();
                if(!visited[top-1])
                {
                    cout<<top<<' ';
                    visited[top-1]=true;
                    N++;
                }
                t=g[top-1].head.link;
                for(int i=0;i<g[top-1].head.data;i++,t=t->link)
                    if(!visited[t->data-1])
                    {
                        s.push(t->data);
                    }
            }
            cout<<"[Size: "<<N<<"]"<<endl;
        }
    }
    cout<<"Number of connected components: "<<cnt<<endl;
    delete []visited;
}
void Graph::dfs()
{
    stack s(V*V);
    int top;
    node *t;
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            s.push(i+1);
            while(!s.isempty())
            {
                top=s.pop();
                if(!visited[top-1])
                {
                    cout<<top<<' ';
                    visited[top-1]=true;
                }
                t=g[top-1].head.link;
                for(int i=0;i<g[top-1].head.data;i++,t=t->link)
                    if(!visited[t->data-1])
                    {
                        s.push(t->data);
                    }
            }
        }
    }
    cout<<endl;
    delete []visited;
}
void Graph::deleteEdge(int u,int v)
{
    if(u<1||u>V||v<1||v>V)
    {
        cout<<"Wrong input. Deletion not possible."<<endl;
        return;
    }
    if(!g[u-1].search(v))
    {
        cout<<"Edge does not exist. Deletion not possible."<<endl;
        return;
    }
    else
    {
        g[u-1].Delete(v);
        if(u!=v)
            g[v-1].Delete(u);
    }

}
int Graph::shortestPath(int u,int v)
{
    int *dist=new int[V];
    bool *spt=new bool[V];
    node *t;
    for(int i=0;i<V;i++)
    {
        dist[i]=-1;
        spt[i]=false;
    }
    dist[u-1]=0;
    for(int i=0;i<V-1;i++)
    {
        u=minDist(dist,spt);
        spt[u-1]=true;
        t=g[u-1].head.link;
        for(int j=0;j<g[u-1].head.data;j++,t=t->link)
        {
            if((dist[t->data-1]==-1||(dist[t->data-1]>dist[u-1]+1))&&(dist[u-1]!=-1))
                dist[t->data-1]=dist[u-1]+1;
        }
    }
    int result=dist[v-1];
    delete []spt;
    delete []dist;
    return result;
}
int Graph::minDist(int *dist,bool *spt)
{
    int m=-1, index;
    for(int i=0;i<V;i++)
    {
        if(!spt[i])
        {
            if(dist[i]==-1&&m==-1)
                index=i;
            else if((dist[i]<m||m==-1)&&dist[i]!=-1)
            {
                index=i;
                m=dist[i];
            }
        }
    }
    return index+1;
}
Graph::Graph(const Graph &c)
{
    V=c.V;
    g=new sll[c.V];
    node *t, *p;
    for(int i=0;i<c.V;i++)
    {

        g[i].head.data=c.g[i].head.data;
        g[i].head.link=NULL;
        t=c.g[i].head.link;
        if(t!=NULL)
        {
            g[i].head.link=g[i].createNewNode(t->data,NULL);
            t=t->link;
            p=g[i].head.link;
            for(int j=1;j<c.g[i].head.data;j++,t=t->link,p=p->link)
                p->link=g[i].createNewNode(t->data,NULL);
        }

    }
}
int main()
{
    Graph g1(9);
    g1.insertEdge(1,2);
    g1.insertEdge(2,3);
    g1.insertEdge(3,4);
    g1.insertEdge(4,5);
    g1.insertEdge(5,1);
    g1.insertEdge(2,5);
    g1.insertEdge(2,4);
    g1.insertEdge(6,7);
    g1.insertEdge(7,7);
    g1.insertEdge(7,8);
    g1.insertEdge(8,9);
    cout<<"Displaying g1:\n";
    g1.displayGraph();
    cout<<"DFS of g1:\n";
    g1.dfs();
    Graph g2=g1;
    g1.deleteEdge(7,7);
    g1.deleteEdge(7,8);
    cout<<"Displaying g1:\n";
    g1.displayGraph();
    cout<<"DFS of g1:\n";
    g1.dfs();
    cout<<"Connected components in g1:\n";
    g1.connectedComponents();
    int dist=g1.shortestPath(1,4);
    if(dist!=-1)
        cout<<"Length of shortest path between vertices 1 and 4 in g1 is: "<<dist<<endl;
    else
        cout<<"Path does not exist"<<endl;
    cout<<"Displaying g2:\n";
    g2.displayGraph();
    cout<<"DFS of g2:\n";
    g2.dfs();
    cout<<"Connected components in g2:\n";
    g2.connectedComponents();
    return 0;
}
