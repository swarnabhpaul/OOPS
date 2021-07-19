#include<iostream>
using namespace std;
int** alloc2DArray(int m,int n);
void read2DArray(int **m,int r,int c);
int** multMatrix(int **m1,int **m2,int r1,int c1,int r2, int c2);
void display2DArray(int **m,int r,int c);
void dealloc2DArray(int **m,int r);
int** cofactor(int **matrix,int index,int n);
int detMatrix(int **matrix,int n);
int main()
{
    int m, n, m2, n2, m3, n3;
    char choice='n';
    int **matrix=NULL;
    cout<<"Enter order of matrix (rows*cols): ";
    cin>>m>>n;
    matrix=alloc2DArray(m,n);
    read2DArray(matrix,m,n);
    cout<<"Want to do matrix multiplication? <y/n>: ";
    cin>>choice;
    if(choice=='y'||choice=='Y')
    {
        int **matrix2=NULL;
        int **res=NULL;
        cout<<"Enter order of second matrix (rows*cols): ";
        cin>>m2>>n2;
        if(n!=m2)
        {
            cout<<"Matrix multiplication not possible.";
        }
        else
        {
            matrix2=alloc2DArray(m2,n2);
            read2DArray(matrix2,m2,n2);
            m3=m;
            n3=n2;
            res=multMatrix(matrix,matrix2,m,n,m2,n2);
            cout<<"Result is:\n";
            display2DArray(res,m3,n3);
            dealloc2DArray(matrix2,m2);
            dealloc2DArray(res,m3);
        }
    }
    if(m==n)
    {
        cout<<"\nDeterminant of first matrix is: "<<detMatrix(matrix,n);
    }
    dealloc2DArray(matrix,m);
    return 0;
}
int** alloc2DArray(int m,int n)
{
    int **t=new int*[m];
    int i;
    for(i=0;i<m;i++)
        t[i]=new int[n];
    return t;
}
void read2DArray(int **m,int r,int c)
{
    int i, j;
    cout<<"Input matrix:\n";
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            cin>>m[i][j];
}
int** multMatrix(int **m1,int **m2,int r1,int c1,int r2, int c2)
{
    int **r=alloc2DArray(r1,c2);
    int i, j, k;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            r[i][j]=0;
            for(k=0;k<c1;k++)
                r[i][j]+=(m1[i][k]*m2[k][j]);
        }
    }
    return r;
}
void dealloc2DArray(int **m,int r)
{
    int i;
    for(i=0;i<r;i++)
        delete[] m[i];
    delete[] m;
}
void display2DArray(int **m,int r,int c)
{
    int i, j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            cout<<m[i][j]<<' ';
        cout<<endl;
    }
}
int detMatrix(int **matrix,int n)
{
    int i, det=0, f=1;
    int **cofMat=NULL;
    if(n==1)
        return matrix[0][0];
    else if(n==2)
        return (matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0]);
    else
    {
        for(i=0;i<n;i++)
        {
            cofMat=cofactor(matrix,i,n);
            det+=(f*matrix[0][i]*detMatrix(cofMat,n-1));
            f=-f;
            dealloc2DArray(cofMat,n-1);
        }
        return det;
    }
}
int** cofactor(int **matrix,int index,int n)
{
    int **cofMat=alloc2DArray(n-1,n-1);
    int i, j, cj=0;
    for(i=1;i<n;i++)
    {
        cj=0;
        for(j=0;j<n;j++)
        {
            if(j!=index)
            {
                cofMat[i-1][cj]=matrix[i][j];
                cj++;
            }
        }
    }
    return cofMat;
}
