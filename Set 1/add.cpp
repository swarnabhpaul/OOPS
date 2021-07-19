#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
string largeAdd(string,string);
int main()
{
    string n1, n2, res;
    cout<<"Input first number: ";
    cin>>n1;
    cout<<"Input second number: ";
    cin>>n2;
    res=largeAdd(n1,n2);
    cout<<"Result is: "<<res;
    ofstream fout;
    fout.open("sum.txt",ios::out);
    fout<<res;
    fout.close();
    return 0;
}
string largeAdd(string n1,string n2)
{
    int l1=n1.length(), l2=n2.length(), c=0, i=0;
    string res="";
    reverse(n1.begin(),n1.end());
    reverse(n2.begin(),n2.end());
    while(i<l1&&i<l2)
    {
        res+=(char)(((c+(int)((n1[i]-'0')+(n2[i]-'0')))%10)+'0');
        c=(c+(int)((n1[i]-'0')+(n2[i]-'0')))/10;
        i++;
    }
    while(i<l1)
    {
        res+=(char)(((c+(int)(n1[i]-'0'))%10)+'0');
        c=(c+(int)(n1[i]-'0'))/10;
        i++;
    }
    while(i<l2)
    {
        res+=(char)(((c+(int)(n2[i]-'0'))%10)+'0');
        c=(c+(int)(n2[i]-'0'))/10;
        i++;
    }
    if(c)
    {
        res+=(char)(c+'0');
    }
    reverse(res.begin(),res.end());
    return res;
}
