using namespace std;
class hashing
{
public:
    sll *ht;
    int htsize;
    int hashfn(int) const;
    hashing(int);
    hashing(const hashing&);
    ~hashing();
    bool Search(int) const;
    void Insert(int);
    void Delete(int);
    void Display() const;
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
int hashing::hashfn(int x) const
{
    return (abs(x)%htsize);
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
bool hashing::Search(int x) const
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
void hashing::Display() const
{
    for(int i=0;i<htsize;i++)
        ht[i].display();
}
