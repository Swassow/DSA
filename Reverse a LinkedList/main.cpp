#include "/Users/swassow/Downloads/stdc++.h"

using namespace std;

class node{
public:
    int data;
    node *link;
};
node *head=NULL,*tmp=NULL;
void creation(int val)
{
    node *newnode;
    newnode=new node();
    newnode->data=val;
    newnode->link=NULL;
    if(head==NULL)
    {
        head=newnode;
        tmp=newnode;
    }
    else
    {
        tmp->link=newnode;
        tmp=newnode;
    }
        
}
void travarse()
{
    node *srt=head;
    while(srt->link!=NULL)
    {
        cout<<srt->data<<" ";
        srt=srt->link;
    }
    cout<<srt->data<<endl;
}
void reverse()
{
    node *prevnode,*nextnode,*crntnode;
    prevnode=NULL;
    nextnode=crntnode=head;
    while(nextnode!=NULL)
    {
        nextnode=crntnode->link;
        crntnode->link=prevnode;
        prevnode=crntnode;
        crntnode=nextnode;
    }
    head=prevnode;
    travarse();
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x= rand()%20;
        creation(x);
    }
    travarse();
    reverse();
}
