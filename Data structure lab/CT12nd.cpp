#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int info;
    node *prev;
    node *next;
};
node *head=NULL,*tail=NULL,*tmp=NULL;
void creation(int item)
{
    node *srt;
    srt=new node();
    srt->info=item;
    srt->prev=NULL;
    srt->next=NULL;
    if(head==NULL)
    {
        head=srt;
        tail=srt;
    }
    else
    {
        tail->next=srt;
        srt->prev=tail;
        tail=srt;
    }
}
void traverse()
{
    node *srt=head;
    while(srt!=NULL)
    {
        cout<<srt->info<<" ";
        srt=srt->next;
    }
    printf("\n");
}
void f_insert()
{
    node *ptr;
    ptr=new node();
    ptr->info=1;
    ptr->next=head;
    ptr->prev=NULL;
    head->prev=ptr;
    head=ptr;
    traverse();

}
void reverse_traverse()
{
    node *ptr=tail;
    while(ptr!=NULL)
    {
        cout<<ptr->info<<" ";
        ptr=ptr->prev;
    }
    printf("\n");
}
void add()
{
    int i=1,j=0,k,l,m,p,s,r=0,t=0;
    node *ptr=tail;
    while(ptr!=NULL)
    {
        k=ptr->info;
        l=k*i;
        j=j+l;
        i=i*10;
        ptr=ptr->prev;
    }
    p=j;
    j=j+1;
    while(p!=0)
    {

        s=p%10;
        if(s==9)
            r++;
        p=p/10;
        t++;

    }
    if(r==t)
    {
        ptr=tail;
        while(r--)
        {
            ptr->info=0;
            ptr=ptr->prev;
        }
        f_insert();
    }
    else
    {
        ptr=tail;
        while(ptr!=NULL)
        {
            m=j%10;
            ptr->info=m;
            ptr=ptr->prev;
            j=j/10;
        }
        traverse();
    }
}
int main()
{
    int n,p;
    cin>>n;
    while(n--)
    {
        cin>>p;
        creation(p);
    }
    add();
}
