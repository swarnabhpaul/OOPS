#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
int far;
float cel;
char ch;
do
{
cout<<"Enter temperature in farenheit: ";
cin>>far;
cel=(float) (far-32)*(5.0/9);
cout<<far<<" far = "<<cel<<" cel"<<endl;
cout<<"Want to continue: <y/n> ";
cin>>ch;
}while(ch=='y'||ch=='Y');
return 0;
}
