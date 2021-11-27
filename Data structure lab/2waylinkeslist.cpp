#include<bits/stdc++.h>

using namespace std;
class node
{
public:
    int info;
    node *prev,*nxt;
};
node *head=NULL,*tail=NULL;

void creation(int item)
{
    node *ptr;
    ptr = new node;

    ptr->info = item;
    ptr->prev = NULL;
    ptr->nxt = NULL;

    if( head == NULL)
    {
        head = ptr;
        tail = ptr;
    }
    else
    {
        tail->nxt=ptr;
        ptr->prev=tail;
        tail=ptr;
    }
}

void f_trav()
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->info<<" ";
        ptr=ptr->nxt;
    }
    cout<<endl;
}
void b_trav()
{
    node *ptr=tail;
    while(ptr!=NULL)
    {
        cout<<ptr->info<<" ";
        ptr=ptr->prev;
    }
    cout<<endl;

}
void f_insert()
{
    int item;
    cin>>item;
    node *ptr;
    ptr=new node();
    ptr->info=item;
    ptr->nxt=head;
    ptr->prev=NULL;
    head->prev=ptr;
    head=ptr;
    f_trav();
    b_trav();

}
void l_insert()
{
    int item;
    cin>>item;
    node *ptr;
    ptr=new node();
    ptr->info=item;
    tail->nxt=ptr;
    ptr->prev=tail;
    tail=ptr;
    f_trav();
    b_trav();
}
void a_insert()
{
    int item;
    cin>>item;
    node *ptr,*srt;
    for(srt=head; ;)
    {
        if(srt->info==item)
        {
            if(srt==tail)
            {
                l_insert();
                return;
            }

            else
            {
                int data;
                cin>>data;
                ptr=new node();
                ptr->info=data;
                ptr->prev=srt;
                ptr->nxt=srt->nxt;
                srt->nxt->prev=ptr;
                srt->nxt=ptr;
                break;
            }
        }
        else
            srt=srt->nxt;
    }
    f_trav();
    b_trav();
}
void before_insert()
{
    int item;
    cin>>item;
    node *ptr,*srt;
    for(srt=head; ;)
    {
        if(srt->info==item)
        {
            if(srt==head)
            {
                f_insert();
                return;
            }

            else
            {
                int data;
                cin>>data;
                ptr=new node();
                ptr->info=data;
                ptr->prev=srt->prev;
                ptr->nxt=srt;

                srt->prev->nxt=ptr;
                srt->prev=ptr;
                break;
            }
        }
        else
            srt=srt->nxt;
    }
    f_trav();
    b_trav();
}
void f_del()
{
    head=head->nxt;
    head->prev=NULL;
    f_trav();
}
void l_del()
{
    tail=tail->prev;
    tail->nxt=NULL;
    f_trav();
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
                f_del();
                return;
            }
            else if(ptr->nxt==NULL)
            {
                l_del();
                return;
            }
            else
            {
                ptr->prev->nxt=ptr->nxt;
                ptr->nxt->prev=tmp;
            }
            break;
        }
        tmp=ptr;
        ptr=ptr->nxt;
        if(ptr==NULL)
        {
            cout<<"Item not found\n"<<endl;
            return;
        }
    }
    f_trav();
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
            if(ptr->nxt->nxt==NULL)
            {
                l_del();
            }
            else
            {
                ptr->nxt=ptr->nxt->nxt;
                ptr->nxt->nxt->prev=ptr;
            }
            break;
        }
        ptr=ptr->nxt;
        if(ptr==NULL)
        {
            cout<<"Item not found\n"<<endl;
            return;
        }
    }
    f_trav();
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
                f_del();
            }
            else
            {
                tmp->prev->nxt=ptr;
                ptr->prev=tmp;
            }
            break;
        }
        tmp=ptr;
        ptr=ptr->nxt;
        if(ptr==NULL)
        {
            cout<<"Item not found\n"<<endl;
            return;
        }
    }
    f_trav();
}
int main()
{
    int n,t;
    cin>>n;
    while(n--)
    {
        creation(rand()%10);
    }
    f_trav();
   //f_del();
   //l_del();
   //given_dlt();
   //after_dlt();
   before_dlt();
}
