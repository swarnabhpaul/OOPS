#include<iostream>
#include<string>
using namespace std;
int main()
{
    string fn, ln, fuln;
    cin>>fn>>ln;
    if(fn==ln)
        cout<<"Wrong input"<<endl;
    fuln=fn+" "+ln;
    cout<<fuln<<endl;
    int x=fuln.find("war",3);
    if(x!=string::npos)
        cout<<x<<endl;
    string sub=fuln.substr(1,3);
    cout<<sub<<endl;
    fuln.insert(2,"ZZ");
    cout<<fuln<<endl;
    fuln.replace(4,2,"XX");
    cout<<fuln<<endl;
    return 0;
}
