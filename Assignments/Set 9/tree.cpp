#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
    node(int,node*,node*);
};
node::node(int d=0,node *l=NULL,node *r=NULL)
{
    data=d;
    left=l;
    right=r;
}
class tree
{
    node head;
    int depth_of_subtree(node *root);
    void Inorder(node *root);
    void Preorder(node *root);
    void create_subtree(node *root);
    void deallocate_nodes(node *root);
public:
    tree();
    ~tree();
    int Find_depth();
    void Display();
    void Longest_path();
    void create_tree();
    void delete_tree();
};
tree::tree()
{
    cout<<"Binary tree created"<<endl;
}
tree::~tree()
{
    deallocate_nodes(head.left);
    head.data=0;
    head.left=head.right=NULL;
    cout<<"Binary tree destroyed"<<endl;
}
void tree::create_tree()
{
    char ch;
    int d;
    cout<<"Does tree have root node? <y/n>: ";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    {
        cout<<"Enter data for root node: ";
        cin>>d;
        head.left=head.right=new node(d,NULL,NULL);
        head.data++;
        create_subtree(head.left);
    }
}
int tree::Find_depth()
{
    return depth_of_subtree(head.left);
}
void tree::Display()
{
    cout<<"Inorder traversal: ";
    Inorder(head.left);
    cout<<endl;
    cout<<"Preorder traversal: ";
    Preorder(head.left);
    cout<<endl;
}
void tree::Longest_path()
{
    int n=Find_depth();
    if(n==0)
    {
        cout<<"No path possible! Tree is empty!"<<endl;
        return;
    }
    int *a=new int[n], i=0, d1, d2;
    node *root=head.left;
    while(root!=NULL)
    {

        a[i]=root->data;
        i++;
        d1=depth_of_subtree(root->left);
        d2=depth_of_subtree(root->right);
        if(d1>=d2)
            root=root->left;
        else
            root=root->right;
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" -> ";
    cout<<"||";
    delete []a;
}
int tree::depth_of_subtree(node *root)
{
    if(root==NULL)
        return 0;
    int d1=depth_of_subtree(root->left)+1, d2=depth_of_subtree(root->right)+1;
    if(d1>=d2)
        return d1;
    return d2;
}
void tree::Inorder(node *root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        cout<<root->data<<' ';
        Inorder(root->right);
    }
}
void tree::Preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<' ';
        Preorder(root->left);
        Preorder(root->right);
    }
}
void tree::create_subtree(node *root)
{
    char ch;
    int d;
    cout<<"Does node have left subtree? <y/n>: ";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    {
        cout<<"Enter data: ";
        cin>>d;
        root->left=new node(d,NULL,NULL);
        head.data++;
        create_subtree(root->left);
    }
    cout<<"Does node have right subtree? <y/n>: ";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    {
        cout<<"Enter data: ";
        cin>>d;
        root->right=new node(d,NULL,NULL);
        head.data++;
        create_subtree(root->right);
    }
}
void tree::deallocate_nodes(node *root)
{
    if(root!=NULL)
    {
        deallocate_nodes(root->left);
        deallocate_nodes(root->right);
        delete root;
    }
}
void tree::delete_tree()
{
    deallocate_nodes(head.left);
    head.data=0;
    head.left=head.right=NULL;
}
int main()
{
    tree t1;
    t1.create_tree();
    t1.Display();
    cout<<"Depth: "<<t1.Find_depth()<<endl;
    cout<<"Longest path: ";
    t1.Longest_path();
    cout<<endl;
    return 0;
}
