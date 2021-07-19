#include<iostream>
using namespace std;
class matrix
{
private:
    int **a;
    int r, c, maxr, maxc;
    int** allocatespace(int,int);
    void deallocatespace();
    matrix* cofactor(int);
    matrix* createCramerMatrix(matrix*,int);
public:
    matrix();
    matrix(int);
    matrix(int,int);
    ~matrix();
    void readmatrix();
    void displayMatrix();
    matrix* addMatrix(matrix*);
    matrix* multMatrix(matrix*);
    int detMatrix();
    void CramerRule(matrix*);
};
int** matrix::allocatespace(int r,int c)
{
    this->r=0;
    this->c=0;
    maxr=r;
    maxc=c;
    int **t=new int*[r];
    for(int i=0;i<r;i++)
        t[i]=new int[c];
    return t;
}
void matrix::deallocatespace()
{
    for(int i=0;i<maxr;i++)
        delete []a[i];
    delete []a;
}
matrix::matrix()
{
    maxr=maxc=10;
    a=allocatespace(maxr,maxc);
    cout<<"Matrix of size "<<maxr<<" * "<<maxc<<" allocated\n";
}
matrix::matrix(int n)
{
    maxr=maxc=n;
    a=allocatespace(n,n);
    cout<<"Matrix of size "<<n<<" * "<<n<<" allocated\n";
}
matrix::matrix(int r,int c)
{
    maxr=r;
    maxc=c;
    a=allocatespace(r,c);
    cout<<"Matrix of size "<<r<<" * "<<c<<" allocated\n";
}
matrix::~matrix()
{
    deallocatespace();
    cout<<"Matrix of size "<<maxr<<" * "<<maxc<<" destroyed\n";
}
void matrix::readmatrix()
{
    do
    {
        cout<<"Enter order of matrix: ";
        cin>>r>>c;
        if(r>maxr||c>maxc||r<0||c<0)
            cout<<"Wrong input. Enter again.\n";
    }while(r>maxr||c>maxc||r<0||c<0);
    int i, j;
    cout<<"Input matrix:\n";
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            cin>>a[i][j];
}
void matrix::displayMatrix()
{
    if(r==0&&c==0)
    {
        cout<<"Matrix is empty\n";
    }
    int i, j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
}
matrix* matrix::addMatrix(matrix *m)
{
    matrix *result=new matrix(r,c);
    if(r!=m->r||c!=m->c)
    {
        cout<<"Matrix addition not possible\n";
        return result;
    }
    int i, j;
    result->r=r;
    result->c=c;
    for(i=0;i<r;i++)
        for(int j=0;j<c;j++)
            result->a[i][j]=a[i][j]+m->a[i][j];
    return result;
}
matrix* matrix::multMatrix(matrix *m)
{
    matrix *result=new matrix(r,m->c);
    if(c!=m->r)
    {
        cout<<"Matrix multiplication not possible\n";
        return result;
    }
    int i, j, k;
    result->r=r;
    result->c=m->c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<m->c;j++)
        {
            result->a[i][j]=0;
            for(k=0;k<c;k++)
                result->a[i][j]+=(a[i][k]*m->a[k][j]);
        }
    }
    return result;
}
int matrix::detMatrix()
{
    if(r!=c)
    {
        cout<<"Determinant not defined\n";
        return -1;
    }
    int i, det=0, f=1;
    matrix *cofmat=NULL;
    if(r==1)
        return a[0][0];
    else if(r==2)
        return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
    else
    {
        for(i=0;i<r;i++)
        {
            cofmat=cofactor(i);
            det+=(f*a[0][i]*cofmat->detMatrix());
            f=-f;
            delete cofmat;
        }
        return det;
    }
}
matrix* matrix::cofactor(int x)
{
    int i, j, cj=0;
    matrix *m=new matrix(r-1,r-1);
    m->r=r-1;
    m->c=r-1;
    for(i=1;i<r;i++)
    {
        cj=0;
        for(j=0;j<c;j++)
        {
            if(j!=x)
            {
                m->a[i-1][cj]=a[i][j];
                cj++;
            }
        }
    }
    return m;
}
void matrix::CramerRule(matrix *m)
{
    if(m->c!=1||r!=c||r!=m->r)
    {
        cout<<"Solution not possible by Cramer's rule\n";
        return;
    }
    matrix *cram=NULL;
    double x;
    int d=detMatrix(), d_i, i;
    for(i=0;i<r;i++)
    {
        cram=createCramerMatrix(m,i);
        d_i=cram->detMatrix();
        delete cram;
        x=double(d_i)/d;
        cout<<"x_"<<i+1<<" = "<<x<<endl;
    }
}
matrix* matrix::createCramerMatrix(matrix *C,int index)
{
    matrix *t=new matrix(r,c);
    t->r=r;
    t->c=c;
    int i, j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        {
            if(j==index)
                t->a[i][j]=C->a[i][0];
            else
                t->a[i][j]=a[i][j];
        }
    return t;
}
int main()
{
    cout<<"Input matrices A and C respectively to solve set of linear equations AX=C by Cramer's rule\n";
    matrix A, C;
    A.readmatrix();
    C.readmatrix();
    A.CramerRule(&C);
    matrix D1[5]={5,4,6,8,10};
    matrix D2[3]={{2,3},{3,4},{4,5}};
    {
        matrix *E=new matrix(4,5);
        matrix *F=new matrix[4];
        cout<<"For matrix E:\n";
        E->readmatrix();
        cout<<"Displaying matrix E:\n";
        E->displayMatrix();
        delete []F;
        delete E;
    }
    return 0;
}
