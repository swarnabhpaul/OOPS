#include<iostream>
#include<stdbool.h>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
    node(int,node*,node*);
};
node::node(int x=0,node *l=NULL,node *r=NULL)
{
    data=x;
    left=l;
    right=r;
}
class BST
{
    node root;
    void deleteTreeRecursively(node*);
    node *createNewNode(int,node*,node*);
    void inorder(node*);
    bool isempty();
    int depth(node*);
    node* minValueNode(node*);
    node* searchparent(node*,int);
    void printlevel(node*,int);
    void postorder(node*);
    node* copytree(node*);
public:
    BST();
    ~BST();
    BST(const BST&);
    void deletebst();
    void insert(int);
    void display();     //uses in-order traversal
    node* search(int);
    int findheight();
    void Delete(int);
    void bfs();         //uses level-order traversal
    void dfs();         //uses post-order traversal
};
bool BST::isempty()
{
    return (root.data==0);
}
node* BST::createNewNode(int x,node *l,node *r)
{
    node *t=new node(x,l,r);
    return t;
}
BST::BST()
{
    root.data=0;
    root.left=root.right=NULL;
    cout<<"BST constructed"<<endl;
}
BST::~BST()
{
    deletebst();
    cout<<"BST destroyed"<<endl;
}
void BST::deletebst()
{
    deleteTreeRecursively(root.right);
    root.data=0;
    root.left=root.right=NULL;
}
void BST::deleteTreeRecursively(node *n)
{
    if(n!=NULL)
    {
        deleteTreeRecursively(n->left);
        deleteTreeRecursively(n->right);
        delete n;
    }
}
void BST::insert(int x)
{
    if(root.data==0)
    {
        root.left=root.right=createNewNode(x,NULL,NULL);
    }
    else
    {
        node *p=root.right, *q;
        while(p!=NULL)
        {
            q=p;
            if(x<p->data)
                p=p->left;
            else
                p=p->right;
        }
        if(x<q->data)
            q->left=createNewNode(x,NULL,NULL);
        else
            q->right=createNewNode(x,NULL,NULL);
    }
    root.data++;
}
void BST::display()
{
    if(isempty())
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    inorder(root.right);
    cout<<endl;
}
void BST::inorder(node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        cout<<r->data<<' ';
        inorder(r->right);
    }
}
node* BST::search(int x)
{
    node *t=root.right;
    while(t!=NULL)
    {
        if(x<t->data)
            t=t->left;
        else if(x>t->data)
            t=t->right;
        else
            return t;
    }
    return t;
}
int BST::findheight()
{
    return depth(root.right);
}
int BST::depth(node *n)
{
    if(n==NULL)
        return 0;
    else
    {
        int l=depth(n->left), r=depth(n->right);
        if(l>r)
            return l+1;
        else
            return r+1;
    }

}
void BST::Delete(int x)
{
    if(isempty())
    {
        cout<<"List is empty. Deletion not possible."<<endl;
        return;
    }
    node *n=search(x);
    if(n==NULL)
    {
        cout<<"Element not found. Deletion not possible."<<endl;
        return;
    }
    node *r, *parent;
    if(n==root.right&&(n->left==NULL||n->right==NULL))
    {
        r=n;
        if(n->left==NULL)
        {
            r=n->right;
        }
        else
        {
            r=n->left;
        }
        delete n;
        root.left=root.right=r;
        root.data--;
    }
    else
    {
        parent=searchparent(root.right,x);
        if(n->left==NULL)
        {
            if(parent->right==n)
                parent->right=n->right;
            else
                parent->left=n->right;
            delete n;
        }
        else if(n->right==NULL)
        {
            if(parent->right==n)
                parent->right=n->left;
            else
                parent->left=n->left;
            delete n;
        }
        else
        {
            node *t=minValueNode(n->right);
            int temp=t->data;
            parent=searchparent(root.right,temp);
            if(t->left==NULL)
            {
                if(parent->right==t)
                    parent->right=t->right;
                else
                    parent->left=t->right;
                delete t;
            }
            else if(t->right==NULL)
            {
                if(parent->right==t)
                    parent->right=t->left;
                else
                    parent->left=t->left;
                delete t;
            }
            n->data=temp;
        }
        root.data--;
    }
}
node* BST::minValueNode(node *t)
{
    if(t==NULL)
        return NULL;
    else
    {
        while(t->left!=NULL)
            t=t->left;
        return t;
    }
}
node* BST::searchparent(node *n,int v)
{
    if(n==NULL)
        return NULL;
    else
    {
        if(n->left!=NULL&&n->left->data==v)
            return n;
        else if(n->right!=NULL&&n->right->data==v)
            return n;
        node *l=searchparent(n->left,v);
        if(l!=NULL)
            return l;
        else
            return searchparent(n->right,v);
    }

}
void BST::bfs()
{
    if(isempty())
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    int h=findheight();
    for(int i=1;i<=h;i++)
        printlevel(root.right,i);
    cout<<endl;
}
void BST::printlevel(node *n,int l)
{
    if(n==NULL)
    {
        return;
    }
    if(l==1)
        cout<<n->data<<' ';
    else
    {
        printlevel(n->left,l-1);
        printlevel(n->right,l-1);
    }
}
void BST::dfs()
{
    if(isempty())
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    postorder(root.right);
    cout<<endl;
}
void BST::postorder(node *n)
{
    if(n!=NULL)
    {
        postorder(n->left);
        postorder(n->right);
        cout<<n->data<<' ';
    }
}
BST::BST(const BST &b)
{
    root.data=b.root.data;
    root.left=root.right=copytree(b.root.right);
}
node* BST::copytree(node *b)
{
    if(b!=NULL)
    {
        node *t=createNewNode(b->data,NULL,NULL);
        t->left=copytree(b->left);
        t->right=copytree(b->right);
        return t;
    }
    else
    {
        return NULL;
    }
}
int main()
{
    BST t1;
    t1.insert(3);
    t1.insert(12);
    t1.insert(18);
    t1.insert(22);
    t1.insert(7);
    t1.insert(0);
    t1.insert(-98);
    t1.insert(123);
    t1.insert(77);
    cout<<"Displaying t1: ";
    t1.display();
    cout<<"BFS of t1: ";
    t1.bfs();
    cout<<"DFS of t1: ";
    t1.dfs();
    BST t2=t1;
    t1.Delete(3);
    cout<<"Displaying t1: ";
    t1.display();
    cout<<"Displaying t2: ";
    t2.display();
    cout<<"Searching for 12 in t1.\n";
    if(t1.search(12)==NULL)
        cout<<"Search unsuccessful. Element not found."<<endl;
    else
        cout<<"Search successful. Element found."<<endl;
    cout<<"Height of tree t1 is: "<<t1.findheight()<<endl;
    return 0;
}
