#include<bits/stdc++.h>

using namespace std;
#define n 5

int top=-1,ara[n];

void push(int x)
{
    if(top==n-1)
        cout<<"The stack is full."<<endl;
    else
    {
        top++;
        ara[top]=x;
    }
}
void pop()
{
    if(top==-1)
        cout<<"The stack is empty"<<endl;
    else
        top--;
}
void display()
{
    if(top==-1)
        cout<<"The stack is empty"<<endl;
    for(int i=top; i>=0; i--)
    {
        cout<<ara[i]<<endl;
    }
}
class node
{
public:
    int info;
    node *link;
};
node *head=NULL,*tmp=NULL;

void creation(int data)
{
    node *ptr;
    ptr=new node();
    ptr->info=data;
    ptr->link=NULL;
    if(head==NULL)
    {
        head=ptr;
        tmp=ptr;
    }
    else
    {
        tmp->link=ptr;
        tmp=ptr;
    }
}
void travarse()
{
    node *srt;
    if(head==NULL)
    {
        cout<<"The stack is empty"<<endl;
    }
    else
    {
        cout<<"The elements are: ";

        for(srt=head; ;)
        {
            if(srt->link!=NULL)
            {
                cout<<srt->info<<" ";
                srt=srt->link;
            }
            else
            {
                cout<<srt->info<<endl;
                break;
            }
        }
    }
}
void push2(int item)
{
    node *ptr;
    ptr=new node();
    ptr->info=item;
    ptr->link=head;
    head=ptr;
}
void pop2()
{
    if(head==NULL)
        cout<<"The stack is empty poping not possible"<<endl;
    else if(head->link==NULL)
        head=NULL;
    else
        head=head->link;
}
int main()
{
    push2(2);
    push2(3);
    push2(4);
    push2(5);
    travarse();
    pop2();
    pop2();
    pop2();
    pop2();
    pop2();
    travarse();
}
