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
void first_dlt()
{
    head=head->next;
    head->prev=NULL;
    traverse();
}
void last_dlt()
{
    tail=tail->prev;
    tail->next=NULL;
    traverse();
}
void given_dlt()
{
    int item;
    cout<<"Enter the item which you want to delete:"<<endl;
    cin>>item;
    node *ptr=head,*tmp=head;
    while(ptr!=NULL)
    {
        if(ptr->info==item)
        {
            if(ptr==head)
            {
                first_dlt();
            }
            else if(ptr->next==NULL)
            {
                last_dlt();
            }
            else
            {
                ptr->prev->next=ptr->next;
                ptr->next->prev=tmp;
            }
            break;
        }
        tmp=ptr;
        ptr=ptr->next;
        if(ptr==NULL)
        {
            cout<<"Item not found\n"<<endl;
            return;
        }
    }
    traverse();
}
void after_dlt()
{
    int item;
    cout<<"Enter the item after which you want to delete:"<<endl;
    cin>>item;
    node *ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->info==item)
        {
            if(ptr->next->next==NULL)
            {
                last_dlt();
            }
            else
            {
                ptr->next=ptr->next->next;
                ptr->next->next->prev=ptr;
            }
            break;
        }
        ptr=ptr->next;
        if(ptr==NULL)
        {
            cout<<"Item not found\n"<<endl;
            return;
        }
    }
    traverse();
}
void before_dlt()
{
    int item;
     cout<<"Enter the item before which you want to delete:"<<endl;
    cin>>item;
    node *ptr=head,*tmp;
    while(ptr!=NULL)
    {
        if(ptr->info==item)
        {
            if(ptr->prev->prev==NULL)
            {
                first_dlt();
            }
            else
            {
                tmp->prev->next=ptr;
                ptr->prev=tmp;
            }
            break;
        }
        tmp=ptr;
        ptr=ptr->next;
        if(ptr==NULL)
        {
            cout<<"Item not found\n"<<endl;
            return;
        }
    }
    traverse();
}
int main()
{
    int n,i;
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    while(n--)
    {
        creation(rand()%10);
    }
    cout<<"press 1 for forward traverse:"<<endl;
    cout<<"press 2 for reverse traverse:"<<endl;
    cout<<"press 3 for first delete:"<<endl;
    cout<<"press 4 for last delete:"<<endl;
    cout<<"press 5 for given item delete:"<<endl;
    cout<<"press 6 for after delete:"<<endl;
    cout<<"press 7 for before delete:"<<endl;
    while(1)
    {
        cin>>i;
        if(i==1)
            traverse();
        else if(i==2)
            reverse_traverse();
        else if(i==3)
            first_dlt();
        else if(i==4)
            last_dlt();
        else if(i==5)
            given_dlt();
        else if(i==6)
            after_dlt();
        else if(i==7)
            before_dlt();
        else if(i==0)
            break;
        else
            cout<<"please enter the right keyword"<<endl;
    }
    return 0;
}
