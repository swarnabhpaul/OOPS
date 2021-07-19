#include<iostream>
#include<stdlib.h>
using namespace std;
class Tool
{	/* Fill in */
protected:
    int strength;
    char type;
public:
    void setStrength(int);
    int getStrength();
    char getType();
};
void Tool::setStrength(int str)
{
    strength=str;
}
int Tool::getStrength()
{
    return strength;
}
char Tool::getType()
{
    return type;
}
/*Implement class Scissors */
class Scissors: public Tool
{
public:
    Scissors(int);
    bool fight(Tool);
};
Scissors::Scissors(int str)
{
    setStrength(str);
    type='s';
}
bool Scissors::fight(Tool t)
{
    char OpType=t.getType();
    int OpStrength=t.getStrength();
    if(OpType=='r')
        return (strength>2*OpStrength);
    else if(OpType=='p')
        return (2*strength>OpStrength);
    else
        return (strength>OpStrength);
}
/*Implement class Paper */
class Paper: public Tool
{
public:
    Paper(int);
    bool fight(Tool);
};
Paper::Paper(int str)
{
    setStrength(str);
    type='p';
}
bool Paper::fight(Tool t)
{
    char OpType=t.getType();
    int OpStrength=t.getStrength();
    if(OpType=='s')
        return (strength>2*OpStrength);
    else if(OpType=='r')
        return (2*strength>OpStrength);
    else
        return (strength>OpStrength);
}
/*Implement class Rock */
class Rock: public Tool
{
public:
    Rock(int);
    bool fight(Tool);
};
Rock::Rock(int str)
{
    setStrength(str);
    type='r';
}
bool Rock::fight(Tool t)
{
    char OpType=t.getType();
    int OpStrength=t.getStrength();
    if(OpType=='p')
        return (strength>2*OpStrength);
    else if(OpType=='s')
        return (2*strength>OpStrength);
    else
        return (strength>OpStrength);
}
int main() {
	// Example main function
	// You may add your own testing code if you like
	Scissors s1(5);
	Paper p1(7);
	Rock r1(15);
	cout << s1.fight(p1) << p1.fight(s1) << endl;
	cout << p1.fight(r1) << r1.fight(p1) << endl;
	cout << r1.fight(s1) << s1.fight(r1) << endl;
	return 0;
}
