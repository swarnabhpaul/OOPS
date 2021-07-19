#include<iostream>
#include<time.h>
using namespace std;
const int n=6;
unsigned long int myrand(unsigned long int);
void displayMarks(int *marks[n],int num[n]);
int findDeptTopper(int *marks,int num);
void findBatchTopper(int *marks[n],int num[n]);
int main()
{
    time_t seconds;
    seconds=time(NULL);
    unsigned long int seed=seconds;
    int *marks[n];
    int i, noOfStud[n], j;
    for(i=0;i<n;i++)
    {
        cout<<"How many students in department "<<i+1<<": ";
        cin>>noOfStud[i];
        marks[i]=new int[noOfStud[i]];
    }
    cout<<"Entering marks of students roll no. wise in each department.";
    for(i=0;i<n;i++)
    {
        for(j=0;j<noOfStud[i];j++)
        {
            seed=myrand(seed);
            marks[i][j]=(seed%100)+1;
        }
    }
    displayMarks(marks,noOfStud);
    for(i=0;i<n;i++)
    {
        int top=findDeptTopper(marks[i],noOfStud[i]);
        cout<<"Topper of department "<<i+1<<" is roll no. "<<top<<" scored "<<marks[i][top-1]<<" marks."<<endl;
    }
    findBatchTopper(marks,noOfStud);
    for(i=0;i<n;i++)
        delete[] marks[i];
    return 0;
}
unsigned long int myrand(unsigned long int x)
{
    unsigned long long int m=2147483647, a=65539;
    unsigned long int r=(x*a)%m;
    return r;
}
void displayMarks(int *marks[n],int num[n])
{
    int i, j;
    cout<<"\nDisplaying marks roll no. wise for each department.\n";
    for(i=0;i<n;i++)
    {
        cout<<"Department "<<i+1<<": ";
        for(j=0;j<num[i];j++)
            cout<<marks[i][j]<<' ';
        cout<<endl;
    }
}
int findDeptTopper(int *marks,int num)
{
    int i, m=0;
    for(i=1;i<num;i++)
        if(marks[i]>marks[m])
            m=i;
    return m+1;
}
void findBatchTopper(int *marks[n],int num[6])
{
    int topDept=0, top=0, i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<num[i];j++)
        {
            if(marks[i][j]>marks[topDept][top])
            {
                topDept=i;
                top=j;
            }
        }
    }
    cout<<"Batch topper in department "<<topDept+1<<", has roll no. "<<top+1<<" and scored "<<marks[topDept][top]<<" marks.";
}
