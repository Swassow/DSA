#include<bits/stdc++.h>
using namespace std;

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
void first_insert(int item)
{
    node *ptr;
    ptr=new node();
    ptr->info=item;
    ptr->link=head;
    head=ptr;
}
void last_delet()
{
    node *srt,*tmp;
    for(srt=head; ;)
    {
        if(srt->link==NULL)
        {
            tmp->link=NULL;
            break;
        }
        else
        {
            tmp=srt;
            srt=srt->link;
        }
    }
}
void rev(int t)
{
    int data;
    node *srt;
    while(t--)
    {
        for(srt=head; ;)
        {
            if(srt->link==NULL)
            {
                data=srt->info;
                break;
            }
            else
                srt=srt->link;
        }
        first_insert(data);
        last_delet();
    }
    travarse();
}

int main()
{
    int n,t;
    cin>>n>>t;
    while(n--)
    {
        creation(rand()%10);
    }
    travarse();
    rev(t);

}
