#include<iostream>
using namespace std;
class Salary
{
    float basic, gross;
public:
    static float da;
    const int bonus;
    const int &dummy;
    float calcsal();
    void display() const;
    Salary(float);
    static void dahike(float);
    friend float average(const Salary&,const Salary&);
};
float Salary::da=1;
void Salary::dahike(float d)
{
    da+=d;
}
Salary::Salary(float b=10000): bonus(2000), dummy(bonus)
{
    gross=basic=b;
}
float Salary::calcsal()
{
    gross=basic+(bonus+(basic*da/100));
    return gross;
}
void Salary::display() const
{
    cout<<"Basic: "<<basic<<endl;
    cout<<"Bonus: "<<bonus<<endl;
    cout<<"Da: "<<(basic*da/100)<<endl;
    cout<<"Gross: "<<gross<<endl;
}
float average(const Salary &s1,const Salary &s2)
{
    float avg=(s1.gross+s2.gross)/2;
    return avg;
}
int main()
{
    Salary emp1(50000), emp2(80000);
    emp1.calcsal();
    emp2.calcsal();
    cout<<"For emp1:"<<endl;
    emp1.display();
    cout<<endl<<"For emp2:"<<endl;
    emp2.display();
    cout<<endl<<"Average gross salary: "<<average(emp1,emp2);
    return 0;
}
