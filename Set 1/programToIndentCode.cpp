#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
string copyString(char*);
void display(string[],int);
void indent(string name)
{
    FILE *f=fopen(name.c_str(),"r");
    if(f==NULL)
    {
        cout<<"File does not exist.";
        return;
    }
    string s[1000];
    char temp[1000];
    int n=0, i, tab=0;
    while(fgets(temp,1000,f)!=NULL)
    {
        s[n]=copyString(temp);
        if(s[n][0]=='}')
        {
            tab--;
        }
        for(i=0;i<tab;i++)
            s[n]='\t'+s[n];
        if(s[n][tab]=='{')
        {
            tab++;
        }
        n++;
    }
    fclose(f);
    display(s,n);
    f=fopen("indent.c","w");
    for(i=0;i<n;i++)
        fprintf(f,"%s",s[i].c_str());
    fclose(f);
}
int main()
{
    string s;
    cout<<"Enter filename to be scanned (with extension): ";
    cin>>s;
    indent(s);
    return 0;
}
string copyString(char *temp)
{
    int i, n=strlen(temp);
    string s;
    for(i=0;i<n;i++)
        s+=temp[i];
    return s;
}
void display(string s[],int n)
{
    int i;
    cout<<"Displaying indented code:\n\n";
    for(i=0;i<n;i++)
        cout<<s[i];
}
