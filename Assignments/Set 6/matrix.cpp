#include<iostream>
#include<stdbool.h>
using namespace std;
class Matrix
{
    int **a;
    int r, c, maxr, maxc;
    int** createMatrix(int,int);
public:
    Matrix(int);
    Matrix(int,int);
    Matrix(const Matrix&);
    ~Matrix();
    Matrix operator + (const Matrix&);
    Matrix operator - (const Matrix&);
    Matrix operator * (const Matrix&);
    Matrix operator / (int);
    void operator ! ();
    bool operator == (const Matrix&);
    void operator = (const Matrix&);
    int* operator [] (int);
    friend ostream& operator << (ostream&,const Matrix&);
    friend istream& operator >> (istream&,Matrix&);
    void* operator new (size_t);
    void* operator new [] (size_t);
    void operator delete (void*);
    void operator delete [] (void*);
};
int** Matrix::createMatrix(int rows,int cols)
{
    int **res;
    res=new int*[rows];
    for(int i=0;i<rows;i++)
        res[i]=new int[cols];
    return res;

}
Matrix::Matrix(int rows,int cols)
{
    r=c=0;
    maxr=rows;
    maxc=cols;
    a=createMatrix(rows,cols);
}
Matrix::Matrix(int Size=10)
{
    r=c=0;
    maxr=maxc=Size;
    a=createMatrix(Size,Size);
}
Matrix::Matrix(const Matrix &m)
{
    r=m.r;
    c=m.c;
    maxr=m.maxr;
    maxc=m.maxc;
    a=createMatrix(maxr,maxc);
    int i, j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            a[i][j]=m.a[i][j];
}
Matrix::~Matrix()
{
    for(int i=0;i<maxr;i++)
        delete []a[i];
    delete []a;
}
Matrix Matrix::operator + (const Matrix &m)
{
    Matrix result(r,c);
    if((r!=m.r)||(c!=m.c))
    {
        cout<<"Invalid operation"<<endl;
        return result;
    }
    result.r=r;
    result.c=c;
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            result.a[i][j]=a[i][j]+m.a[i][j];
    return result;
}
Matrix Matrix::operator - (const Matrix &m)
{
    Matrix result(r,c);
    if((r!=m.r)||(c!=m.c))
    {
        cout<<"Invalid operation"<<endl;
        return result;
    }
    result.r=r;
    result.c=c;
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            result.a[i][j]=a[i][j]-m.a[i][j];
    return result;
}
Matrix Matrix::operator * (const Matrix &m)
{
    Matrix result(r,m.c);
    if(c!=m.r)
    {
        cout<<"Invalid operation"<<endl;
        return result;
    }
    result.r=r;
    result.c=m.c;
    int i, j, k;
    for(i=0;i<r;i++)
        for(j=0;j<m.c;j++)
        {
            result.a[i][j]=0;
            for(k=0;k<c;k++)
                result.a[i][j]+=(a[i][k]*m.a[k][j]);
        }
    return result;
}
Matrix Matrix::operator / (int d)
{
    Matrix result(r,c);
    if(d==0)
    {
        cout<<"Invalid operation"<<endl;
        return result;
    }
    result.r=r;
    result.c=c;
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            result.a[i][j]=a[i][j]/d;
    return result;
}
void Matrix::operator ! ()
{
    int i, j, temp;
    Matrix t(c,r);
    if((r>maxc)||(c>maxr))
    {
        cout<<"Invalid operation"<<endl;
        return;
    }
    for(i=0;i<c;i++)
        for(j=0;j<r;j++)
        {
            t.a[i][j]=a[j][i];
        }
    temp=r;
    r=c;
    c=temp;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            a[i][j]=t.a[i][j];
}
bool Matrix::operator == (const Matrix &m)
{
    int i, j;
    if((r!=m.r)||(c!=m.c))
        return false;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(a[i][j]!=m.a[i][j])
                return false;
    return true;
}
void Matrix::operator = (const Matrix &m)
{
    if((m.r>maxr)||(m.c>maxc))
    {
        cout<<"Invalid operation"<<endl;
        return;
    }
    r=m.r;
    c=m.c;
    int i, j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            a[i][j]=m.a[i][j];
}
int* Matrix::operator [] (int index)
{
    if(index<0||index>=r)
    {
        cout<<"Out of bound access\n";
        return NULL;
    }
    return a[index];
}
ostream& operator << (ostream &f,const Matrix &m)
{
    int i, j;
    for(i=0;i<m.r;i++)
    {
        for(j=0;j<m.c;j++)
            f<<m.a[i][j]<<' ';
        f<<endl;
    }
    return f;
}
istream& operator >> (istream &f,Matrix &m)
{
    cout<<"Enter order of matrix: ";
    f>>m.r>>m.c;
    while((m.r>m.maxr)||(m.c>m.maxc)||(m.r<0)||(m.c<0))
    {
        cout<<"Invalid input"<<endl;
        cout<<"Enter order of matrix: ";
        f>>m.r>>m.c;
    }
    cout<<"Enter matrix:\n";
    int i, j;
    for(i=0;i<m.r;i++)
        for(j=0;j<m.c;j++)
            f>>m.a[i][j];
    return f;
}
void* Matrix::operator new (size_t size)
{
    cout<<"Overloaded new with size "<<size<<endl;
    void *p=NULL;
    p=malloc(size);
    return p;
}
void* Matrix::operator new [] (size_t size)
{
    cout<<"Overloaded new [] with size "<<size<<endl;
    void *p=NULL;
    p=malloc(size);
    return p;
}
void Matrix::operator delete (void *p)
{
    cout<<"Overloaded delete"<<endl;
    free(p);
}
void Matrix::operator delete [] (void *p)
{
    cout<<"Overloaded delete []"<<endl;
    free(p);
}
int main()
{
    Matrix m1, m2;
    cout<<"Enter m1 and m2:\n";
    cin>>m1>>m2;
    cout<<"\nDisplaying matrices:\n";
    cout<<m1<<endl<<m2<<endl<<m1+m2<<endl<<m1-m2<<endl;
    if(m1==m2)
        cout<<"m1 and m2 are equal\n";
    Matrix m3, m4;
    cout<<"Enter m3 and m4:\n";
    cin>>m3>>m4;
    cout<<"\nDisplaying matrices:\n";
    cout<<m3*m4<<endl;
    !m3;
    cout<<m3<<endl;
    int i, j;
    cout<<"Enter indices of element to display in m3: ";
    cin>>i>>j;
    if(m3[i]!=NULL)
        cout<<"Element is: "<<m3[i][j]<<endl;
    Matrix m5(m3);
    m4=m5;
    cout<<"\nDisplaying matrices:\n";
    cout<<m4<<endl<<m5<<endl;
    int n;
    cout<<"Enter number to divide m5 by: ";
    cin>>n;
    cout<<"\nDisplaying matrices:\n";
    cout<<m5/n<<endl;
    Matrix *pm1, *pm2;
    pm1=new Matrix(m1);
    pm2=new Matrix[3];
    for(i=0;i<3;i++)
        pm2[i]=m2;
    cout<<"\nDisplaying matrices:\n";
    cout<<(*pm1)<<endl;
    for(i=0;i<3;i++)
        cout<<pm2[i]<<endl;
    delete []pm2;
    delete pm1;
    return 0;
}
