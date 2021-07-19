#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string factorial(int);
string multiply(string,int,int*);
int main()
{
    int n;
    cout<<"Input n: ";
    cin>>n;
    string result=factorial(n);
    cout<<"Result is: "<<result<<endl;
    return 0;
}
string factorial(int n)
{
    string result="1";
    int len=1, i;
    for(i=1;i<=n;i++)
        result=multiply(result,i,&len);
    reverse(result.begin(),result.end());
    return result;
}
string multiply(string s,int x,int *len)
{
    int i, d, c=0;
    for(i=0;i<(*len);i++)
    {
        d=(int(s[i]-'0'))*x+c;
        c=d/10;
        d%=10;
        s[i]=char(d+'0');
    }
    while(c)
    {
        s+=char((c%10)+'0');
        c/=10;
        (*len)++;
    }
    return s;
}
