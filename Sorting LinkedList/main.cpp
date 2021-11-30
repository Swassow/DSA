//#include<bits/stdc++.h>
#include "/Users/swassow/Downloads/stdc++.h"
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
void sw(node *p,node *q)
{
    int tmp;
    tmp=p->info;
    p->info=q->info;
    q->info=tmp;
}
void bsort()
{
    cout<<"After sorting: "<<endl;
    int i;
    do
    {
        i=0;
        node *qtr=NULL,*ptr=head;
        while(ptr->link!=qtr)
        {
            if(ptr->info>ptr->link->info)
            {
                sw(ptr,ptr->link);
                i=1;
            }
            ptr=ptr->link;
        }
        qtr=ptr;
    }while(i);
    travarse();
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        creation(rand()%10);
    }
    travarse();
    bsort();

}
