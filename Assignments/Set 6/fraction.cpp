#include<iostream>
#include<algorithm>
#include<stdbool.h>
using namespace std;
class Fraction
{
    int a, b;                               /* Fraction is represented by a/b, where a is numerator and b is denominator */
public:
    Fraction(int,int);
    Fraction operator + (const Fraction&);
    Fraction operator - (const Fraction&);
    Fraction operator * (const Fraction&);
    Fraction operator / (const Fraction&);
    void operator * ();
    bool operator == (const Fraction&);
    bool operator != (const Fraction&);
    bool operator < (const Fraction&);
    bool operator > (const Fraction&);
    void operator = (const Fraction&);
    int operator [] (int);
    friend ostream& operator << (ostream&,const Fraction&);
    friend istream& operator >> (istream&,Fraction&);
};
Fraction::Fraction(int n=0,int d=1)
{
    a=n;
    b=d;
}
Fraction Fraction::operator + (const Fraction &z)
{
    int lcm=abs(b*(z.b/__gcd(abs(b),abs(z.b)))), n=a*(lcm/b)+z.a*(lcm/z.b);
    int g=__gcd(abs(n),abs(lcm));
    return Fraction(n/g,lcm/g);
}
Fraction Fraction::operator - (const Fraction &z)
{
    int lcm=abs(b*(z.b/__gcd(abs(b),abs(z.b)))), n=a*(lcm/b)-z.a*(lcm/z.b);
    int g=__gcd(abs(n),abs(lcm));
    return Fraction(n/g,lcm/g);
}
Fraction Fraction::operator * (const Fraction &z)
{
    int n=a*z.a, d=b*z.b, g=__gcd(abs(n),abs(d));
    if(d<0)
    {
        n=-n;
        d=-d;
    }
    return Fraction(n/g,d/g);
}
Fraction Fraction::operator / (const Fraction &z)
{
    int n=a*z.b, d=b*z.a, g=__gcd(abs(n),abs(d));
    if(d<0)
    {
        n=-n;
        d=-d;
    }
    return Fraction(n/g,d/g);
}
void Fraction::operator * ()
{
    int g=__gcd(abs(a),abs(b));
    a/=g;
    b/=g;
    if(b<0)
    {
        a=-a;
        b=-b;
    }
}
bool Fraction::operator == (const Fraction &z)
{
    int lcm=abs(b*(z.b/__gcd(abs(b),abs(z.b))));
    return ((a*(lcm/b))==(z.a*(lcm/z.b)));
}
bool Fraction::operator != (const Fraction &z)
{
    int lcm=abs(b*(z.b/__gcd(abs(b),abs(z.b))));
    return ((a*(lcm/b))!=(z.a*(lcm/z.b)));
}
bool Fraction::operator < (const Fraction &z)
{
    int lcm=abs(b*(z.b/__gcd(abs(b),abs(z.b))));
    return ((a*(lcm/b))<(z.a*(lcm/z.b)));
}
bool Fraction::operator > (const Fraction &z)
{
    int lcm=abs(b*(z.b/__gcd(abs(b),abs(z.b))));
    return ((a*(lcm/b))>(z.a*(lcm/z.b)));
}
void Fraction::operator = (const Fraction &z)
{
    a=z.a;
    b=z.b;
}
int Fraction::operator [] (int index)
{
    if(index==0)
        return a;
    return b;
}
ostream& operator << (ostream &f,const Fraction &z)
{
    f<<z.a<<'/'<<z.b;
    return f;
}
istream& operator >> (istream &f,Fraction &z)
{
    f>>z.a>>z.b;
    return f;
}
int main()
{
    Fraction f1, f2, f3, f4;
    cout<<"Input f1 and f2 respectively:\n";
    cin>>f1>>f2;
    cout<<f1+f2<<endl<<f1-f2<<endl<<f1*f2<<endl<<f1/f2<<endl;
    cout<<"Input f3 and f4 respectively:\n";
    cin>>f3>>f4;
    if(f3==f4)
        cout<<"They are equal.\n";
    if(f3!=f4)
        cout<<"They are not equal.\n";
    if(f3<f4)
        cout<<"f3 is lesser.\n";
    if(f3>f4)
        cout<<"f3 is greater.\n";
    *f3;
    *f4;
    cout<<f3<<endl<<f4<<endl;
    f4=f3;
    cout<<f3<<endl<<f4<<endl;
    cout<<"Numerator(f3): "<<f3[0]<<endl<<"Denominator(f3): "<<f3[1]<<endl;
    return 0;
}
