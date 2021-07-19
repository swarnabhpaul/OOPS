#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
void plotCosine();
void plotExponential();
int main()
{
    int choice;
    cout<<"Enter choice:\n1. Plot cosine\n2. Plot exponential\n";
    cin>>choice;
    for(int i=0;i<=110;i++)
        cout<<'=';
    cout<<endl;
    if(choice==1)
        plotCosine();
    else if(choice==2)
        plotExponential();
    else
        cout<<"Wrong choice.";
    return 0;
}
void plotCosine()
{
    int a, b, s, x, i;
    char c;
    cout<<"Enter the starting angle (in degrees): ";  cin>>a;
    cout<<"Enter the ending angle (in degrees): ";    cin>>b;
    cout<<"Enter the step length: ";                  cin>>s;
    cout<<"Enter the fill character: ";               cin>>c;
    for(i=a;i<=b;i+=s)
    {
        x=floor(cos(i*3.14/180)*50);
        if(x>=0)
        {
            cout<<setw(55)<<setfill(' ')<<'|'<<setw(x)<<setfill(c)<<'+'<<endl;
        }
        else
        {
            x=abs(x);
            cout<<setw(55-x)<<setfill(' ')<<'+'<<setw(x)<<setfill(c)<<'|'<<endl;
        }
    }
}
void plotExponential()
{
    int a, b, s, x, i;
    char c;
    cout<<"Enter the starting coordinate: ";  cin>>a;
    cout<<"Enter the ending coordinate: ";    cin>>b;
    cout<<"Enter the step length: ";          cin>>s;
    cout<<"Enter the fill character: ";       cin>>c;
    for(i=a;i<=b;i+=s)
    {
        x=floor(exp(i));
        if(x>100)
            x=100;
        cout<<setw(5)<<setfill(' ')<<'|'<<setw(x)<<setfill(c)<<'+'<<endl;
    }
}
