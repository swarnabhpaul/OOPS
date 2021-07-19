#include<iostream>
#include<stdbool.h>
using namespace std;
class Complex
{
    float real, img;
public:
    Complex(float,float);
    Complex operator + (const Complex&);
    Complex operator - (const Complex&);
    Complex operator * (const Complex&);
    Complex operator / (const Complex&);
    Complex operator ! ();
    bool operator == (const Complex&);
    bool operator != (const Complex&);
    void operator = (const Complex&);
    float operator [] (int);
    friend ostream& operator << (ostream&,const Complex&);
    friend istream& operator >> (istream&,Complex&);
};
Complex::Complex(float r=0,float i=0)
{
    real=r;
    img=i;
}
Complex Complex::operator + (const Complex &z)
{
    return Complex(real+z.real,img+z.img);
}
Complex Complex::operator - (const Complex &z)
{
    return Complex(real-z.real,img-z.img);
}
Complex Complex::operator * (const Complex &z)
{
    return Complex(real*z.real-img*z.img,real*z.img+img*z.real);
}
Complex Complex::operator / (const Complex &z)
{
    float d=z.real*z.real+z.img*z.img;
    return Complex((real*z.real+img*z.img)/d,(img*z.real-real*z.img)/d);
}
Complex Complex::operator ! ()
{
    return Complex(real,-img);
}
bool Complex::operator == (const Complex &z)
{
    return ((real==z.real)&&(img==z.img));
}
bool Complex::operator != (const Complex &z)
{
    return ((real!=z.real)||(img!=z.img));
}
void Complex::operator = (const Complex &z)
{
    real=z.real;
    img=z.img;
}
float Complex::operator [] (int index)
{
    if(index==0)
        return real;
    return img;
}
ostream& operator << (ostream &f,const Complex &z)
{
    f<<z.real;
    if(z.img>=0)
        f<<'+';
    f<<z.img<<'j';
    return f;
}
istream& operator >> (istream &f,Complex &z)
{
    f>>z.real>>z.img;
    return f;
}
int main()
{
    Complex z1, z2, z3, z4;
    cout<<"Input z1 and z2 respectively:\n";
    cin>>z1>>z2;
    cout<<z1+z2<<endl<<z1-z2<<endl<<z1*z2<<endl<<z1/z2<<endl;
    cout<<!z1<<endl<<!z2<<endl;
    if(z1==z2)
        cout<<"They are equal.\n";
    if(z1!=z2)
        cout<<"They are not equal.\n";
    cout<<"Input z3: ";
    cin>>z3;
    z4=z3;
    cout<<z3<<endl<<z4<<endl;
    cout<<"Re(z3): "<<z3[0]<<endl;
    cout<<"Im(z3): "<<z3[1]<<endl;
    return 0;
}
