#include <iostream>
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
int main()
{
    node<string,5> *n=new node<string,5>("Paul");
    cout<<n->data<<' '<<n->e;
    return 0;
}
