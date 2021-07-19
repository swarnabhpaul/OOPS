#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"myMatrix.h"
using namespace std;
void solve(int **a,int **c,int n);
int **createCramerMatrix(int **a,int **c,int n,int index);
void randomInput2DArray(int **m,int r,int c);
int main()
{
    int n;
    int **a=NULL;
    int **c=NULL;
    time_t seconds=time(NULL);
    srand(seconds);
    cout<<"Input no: of variables: ";
    cin>>n;
    cout<<"The program uses Cramer's to solve a system of linear equations AX=C where matrix A (set of coefficients) and matrix C are taken as inputs.\n";
    a=alloc2DArray(n,n);
    randomInput2DArray(a,n,n);
    cout<<"Matrix A after random input:\n";
    display2DArray(a,n,n);
    c=alloc2DArray(n,1);
    randomInput2DArray(c,n,1);
    cout<<"Matrix C after random input:\n";
    display2DArray(c,n,1);
    cout<<"\nSolution is:\n";
    solve(a,c,n);
    dealloc2DArray(a,n);
    dealloc2DArray(c,n);
    return 0;
}
void solve(int **a,int **c,int n)
{
    int **cram=NULL;
    double x;
    int d=detMatrix(a,n), d_i, i;
    if(d==0)
    {
        cout<<"This equation cannot be solved.\n";
        return;
    }
    for(i=0;i<n;i++)
    {
        cram=createCramerMatrix(a,c,n,i);
        d_i=detMatrix(cram,n);
        dealloc2DArray(cram,n);
        x=double(d_i)/d;
        cout<<"x_"<<i+1<<" = "<<x<<endl;
    }
}
int **createCramerMatrix(int **a,int **c,int n,int index)
{
    int i, j;
    int **cram=alloc2DArray(n,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j==index)
                cram[i][j]=c[i][0];
            else
                cram[i][j]=a[i][j];
        }
    }
    return cram;
}
void randomInput2DArray(int **m,int r,int c)
{
    int i, j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            m[i][j]=(rand()%100);
}
