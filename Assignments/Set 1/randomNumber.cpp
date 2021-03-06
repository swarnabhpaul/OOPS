#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
unsigned long int myrand(unsigned long int);
using namespace std;
int main()
{
    unsigned long int myRandNum, sysRandNum, myseed;
    int o1[5], o2[5];
    double chi1, chi2;
    time_t seconds;
    int n, i;
    seconds=time(NULL);
    cout<<"The time as seed: "<<seconds<<endl;
    myseed=seconds;
    srand(seconds);
    cout<<"How many numbers?: ";
    cin>>n;
    cout<<setw(40)<<"Nos. generated by myrand()"<<setw(40)<<"Nos. generated by rand()"<<endl;
    for(int i=0;i<5;i++)
        o1[i]=o2[i]=0;
    for(int i=1;i<=n;i++)
    {
        myseed=myrand(myseed);
        myRandNum=(myseed%50)+1;
        sysRandNum=(rand()%50)+1;
        cout<<setw(40)<<myRandNum<<setw(40)<<sysRandNum<<endl;
        if(myRandNum<=10)
            o1[0]++;
        else if(myRandNum<=20)
            o1[1]++;
        else if(myRandNum<=30)
            o1[2]++;
        else if(myRandNum<=40)
            o1[3]++;
        else
            o1[4]++;
        if(sysRandNum<=10)
            o2[0]++;
        else if(sysRandNum<=20)
            o2[1]++;
        else if(sysRandNum<=30)
            o2[2]++;
        else if(sysRandNum<=40)
            o2[3]++;
        else
            o2[4]++;
    }
    chi1=chi2=0.0;
    for(i=0;i<5;i++)
    {
        chi1+=(((o1[i]-(n/5.0))*(o1[i]-(n/5.0)))/(n/5.0));
        chi2+=(((o2[i]-(n/5.0))*(o2[i]-(n/5.0)))/(n/5.0));
    }
    cout<<"Chi square test value of random nos. generated by myrand(): "<<chi1<<endl;
    cout<<"Chi square test value of random nos. generated by rand(): "<<chi2<<endl;
    if(chi1<23.6)
        cout<<"Chi square test value of myrand() is acceptable."<<endl;
    else
        cout<<"Chi square test value of myrand() is not acceptable."<<endl;
    if(chi2<23.6)
        cout<<"Chi square test value of rand() is acceptable."<<endl;
    else
        cout<<"Chi square test value of rand() is not acceptable."<<endl;
    return 0;
}
unsigned long int myrand(unsigned long int x)
{
    unsigned long long int m=2147483647, a=65539;
    unsigned long int r=(x*a)%m;
    return r;
}
