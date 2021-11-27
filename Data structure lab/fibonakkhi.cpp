#include <bits/stdc++.h>
using namespace std;

class student
{
    char Name[100];
    char Id[20];
public:
    student(char *name,char *id)
    {
        strcpy(student::Name,name);
        strcpy(student::Id,id);
    }
    student()
    {
        strcpy(student::Name,"No name");
        strcpy(student::Id,"No id");
    }
    void setvalus(char *name,char *id)
    {
        strcpy(student::Name,name);
        strcpy(student::Id,id);
    }
    void disp()
    {
        cout<<Name<<endl;
        cout<<Id<<endl;
    }
};

class registation:public student
{
    float Regfees;
    char Regdate[20];
public:
    registation(char *name,char *id,float fees,char *date):student(name,id)
    {
        Regfees=fees;
        strcpy(registation::Regdate,date);
    }
    registation()
    {

    }
    void show()
    {
        disp();
        cout<<Regfees<<endl;
        cout<<Regdate<<endl;
    }
};
class base
{
public:
    void showmsg()
    {
        cout<<"This is from base class"<<endl;
    }
    base()
    {
        cout<<"Base constructor"<<endl;
    }
    ~base()
    {
        cout<<"Base destructor"<<endl;
    }
};
class derived :public base
{
public:
    void showmsg()
    {
        cout<<"This is from derived class"<<endl;
    }
    derived()
    {
        cout<<"Derived constructor"<<endl;
    }
    ~derived()
    {
        cout<<"Derived destructor"<<endl;
    }
};
int main()
{
    derived obj;

}
