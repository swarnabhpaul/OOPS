#include<iostream>
#include<iomanip>
using namespace std;
void printPattern(int);
int main()
{
    int n, i, j;
    cout<<"Enter n: ";
    cin>>n;
    printPattern(n);
    return 0;
}
void printPattern(int n)
{
    int i, j;
    for(i=1;i<=n;i++)
    {
        cout<<setw(i)<<i;
        for(j=i+1;j<=n;j++)
            cout<<j;
        j--;
        while(j>i)
        {
            j--;
            cout<<j;
        }
        cout<<endl;
    }
    for(i=1;i<n;i++)
    {
        cout<<setw(n-i)<<n-i;
        for(j=n-i+1;j<=n;j++)
            cout<<j;
        j--;
        while(j>n-i)
        {
            j--;
            cout<<j;
        }
        cout<<endl;
    }
}
