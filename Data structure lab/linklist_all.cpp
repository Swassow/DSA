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
void first_insert()
{
    int item;
    cout<<"Enter the number which you want to insert: "<<endl;
    cin>>item;
    node *ptr;
    ptr=new node();
    ptr->info=item;
    ptr->link=head;
    head=ptr;
    travarse();
}
void last_insert()
{
    int item;
    cout<<"Enter the number which you want to insert: "<<endl;
    cin>>item;
    node *ptr,*srt;
    ptr=new node();
    ptr->info=item;
    ptr->link=NULL;
    for(srt=head; ;)
    {
        if(srt->link==NULL)
        {
            srt->link=ptr;
            break;
        }
        else
        {
            srt=srt->link;
        }
    }
    travarse();
}
void before_insert()
{
    int item;
    cout<<"Enter the number before you want to insert: "<<endl;
    cin>>item;
    node *srt,*tmp;
    for(srt=head; ;)
    {
        if(srt->info==item)
        {
            if(srt==head)
                first_insert();
            else
            {
                int data;
                cout<<"Enter the number which you want to insert: "<<endl;
                cin>>data;
                node *ptr;
                ptr=new node();
                ptr->info=data;
                ptr->link=srt;
                tmp->link=ptr;
                break;

            }
        }
        else
        {
            tmp=srt;
            srt=srt->link;
        }
        if(srt==NULL)
        {
            cout<<"Data not found"<<endl;
            return;
        }

    }
    travarse();
}
void after_insert()
{
    int item;
    cout<<"Enter the number after you want to insert: "<<endl;
    cin>>item;
    node *srt;
    for(srt=head; ;)
    {
        if(srt->info==item)
        {
            if(srt->link==NULL)
                last_insert();
            else
            {
                int data;
                cout<<"Enter the number which you want to insert: "<<endl;
                cin>>data;
                node *ptr;
                ptr=new node();
                ptr->info=data;
                ptr->link=srt->link;
                srt->link=ptr;
                break;
            }
        }
        else
        {
            srt=srt->link;
        }
        if(srt==NULL)
        {
            cout<<"Data not found"<<endl;
            return;
        }
    }
    travarse();
}
void first_delet()
{
    head=head->link;
    travarse();
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
    travarse();
}
void given_delet()
{
    int item;
    cout<<"Enter the number which you want to delete: "<<endl;
    cin>>item;
    node *srt,*tmp=head;
    for(srt=head; ;)
    {
        if(srt->info==item)
        {
            if(srt==head)
            {
                first_delet();
                return;
            }

            else if(srt->link==NULL)
            {
                last_delet();
                return;
            }

            else
            {
                tmp->link=srt->link;
                break;
            }

        }
        else
        {
            tmp=srt;
            srt=srt->link;
        }
        if(srt==NULL)
        {
            cout<<"Data not found"<<endl;
            break;
        }
    }
    travarse();
}
void after_delet()
{
    int item;
    cout<<"Enter the number after which you want to delete: "<<endl;
    cin>>item;
    node *srt;
    for(srt=head; ;)
    {
        if(srt->info==item)
        {
            if(srt->link==NULL)
            {
                cout<<"Deletion not possible";
                return ;
            }
            else
            {
                srt->link=srt->link->link;
                break;
            }
        }
        else
            srt=srt->link;
        if(srt==NULL)
        {
            cout<<"Data not found";
            return;
        }
    }
    travarse();
}
void before_delet()
{
    node *ptr,*tmp=NULL,*prev=NULL;
    int item;
    cout<<"Enter the number before which you want to delete: "<<endl;
    cin>>item;
    for(ptr=head; ;)
    {
        if(ptr->info==item)
        {
            if(ptr==head)
            {
                cout<<"Deletion not possible";
                return;
            }
            else if(ptr==head->link)
            {
                first_delet();
                return;
            }

            prev->link=ptr;
            break;

        }
        else
        {
            prev=tmp;
            tmp=ptr;
            ptr=ptr->link;

        }
        if(ptr==NULL)
        {
            cout<<"Data not found";
            return;
        }
    }
    travarse();
}
//2way linkedlist

class node2
{
public:
    int info;
    node2 *prev,*nxt;
};
node2 *head2=NULL,*tail=NULL;

void creation2(int item)
{
    node2 *ptr;
    ptr = new node2;

    ptr->info = item;
    ptr->prev = NULL;
    ptr->nxt = NULL;

    if( head2 == NULL)
    {
        head2 = ptr;
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
    node2 *ptr=head2;
    cout<<"The elements are(forward): ";
    while(ptr!=NULL)
    {
        cout<<ptr->info<<" ";
        ptr=ptr->nxt;
    }
    cout<<endl;
}
void b_trav()
{
    node2 *ptr=tail;
    cout<<"The elements are(backward): ";
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
    cout<<"Enter the number which you want to insert: "<<endl;
    cin>>item;
    node2 *ptr;
    ptr=new node2();
    ptr->info=item;
    ptr->nxt=head2;
    ptr->prev=NULL;
    head2->prev=ptr;
    head2=ptr;
    f_trav();
    b_trav();

}
void l_insert()
{
    int item;
    cout<<"Enter the number which you want to insert: "<<endl;
    cin>>item;
    node2 *ptr;
    ptr=new node2();
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
    cout<<"Enter the number which you want to insert: "<<endl;
    cin>>item;
    node2 *ptr,*srt;
    for(srt=head2; ;)
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
                ptr=new node2();
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
void b_insert()
{
    int item;
    cout<<"Enter the number which you want to insert: "<<endl;
    cin>>item;
    node2 *ptr,*srt;
    for(srt=head2; ;)
    {
        if(srt->info==item)
        {
            if(srt==head2)
            {
                f_insert();
                return;
            }

            else
            {
                int data;
                cin>>data;
                ptr=new node2();
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
    head2=head2->nxt;
    head2->prev=NULL;
    f_trav();
    b_trav();
}
void l_del()
{
    tail=tail->prev;
    tail->nxt=NULL;
    f_trav();
    b_trav();
}
void given_dlt()
{
    int item;
    cout<<"Enter the item which you want to delete:"<<endl;
    cin>>item;
    node2 *ptr=head2,*tmp=head2;
    while(ptr!=NULL)
    {
        if(ptr->info==item)
        {
            if(ptr==head2)
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
    b_trav();
}
void after_dlt()
{
    int item;
    cout<<"Enter the item after which you want to delete:"<<endl;
    cin>>item;
    node2 *ptr=head2;
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
    b_trav();
}
void before_dlt()
{
    int item;
    cout<<"Enter the item before which you want to delete:"<<endl;
    cin>>item;
    node2 *ptr=head2,*tmp;
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
    b_trav();
}
int main()
{
    int n,p,q,r,s,x,y;
    cout<<"Enter number of elements : "<<endl;
    cin>>n;
    cout<<"Press 1 for manual input."<<endl;
    cout<<"press 2 for automatic input."<<endl;
    cin>>x;
    if(x==1)
    {
        cout<<"Enter the numbers"<<endl;
        while(n--)
        {
            cin>>y;
            creation(y);
            creation2(y);
        }
    }
    else if(x==2)
    {
        while(n--)
        {
            creation(rand()%10);
            creation2(rand()%10);
        }
    }

    while(1)
    {
        cout<<"press 1 for 1way linked list"<<endl;
        cout<<"press 2 for 2way linked list"<<endl;
        cout<<"Press 0 for close the program"<<endl;
        cin>>p;
        if(p==1)
        {
            travarse();
            cout<<"press 1 for insertion"<<endl;
            cout<<"press 2 for deletion"<<endl;
            cin>>q;
            if(q==1)
            {
                cout<<"press 1 for first insertion"<<endl;
                cout<<"press 2 for last insertion"<<endl;
                cout<<"press 3 for after insertion"<<endl;
                cout<<"press 4 for before insertion"<<endl;
                cout<<"press 0 for return"<<endl;
                while(1)
                {
                    cin>>r;
                    if(r==1)
                        first_insert();
                    else if(r==2)
                        last_insert();
                    else if(r==3)
                        after_insert();
                    else if(r==4)
                        before_insert();
                    else if(r==0)
                        break;
                    else
                        cout<<"Please enter the right key"<<endl;
                }
            }
            else if(q==2)
            {
                cout<<"press 1 for first deletion"<<endl;
                cout<<"press 2 for last deletion"<<endl;
                cout<<"press 3 for given item deletion"<<endl;
                cout<<"press 4 for after deletion"<<endl;
                cout<<"press 5 for before deletion"<<endl;
                cout<<"press 0 for return "<<endl;
                while(1)
                {
                    cin>>r;
                    if(r==1)
                        first_delet();
                    else if(r==2)
                        last_delet();
                    else if(r==3)
                        given_delet();
                    else if(r==4)
                        after_delet();
                    else if(r==5)
                        before_delet();
                    else if(r==0)
                        break;
                    else
                        cout<<"Please enter the right key"<<endl;
                }
            }

        }
        else if(p==2)
        {
            f_trav();
            b_trav();
            cout<<"press 1 for insertion"<<endl;
            cout<<"press 2 for deletion"<<endl;
            cin>>q;
            if(q==1)
            {
                cout<<"press 1 for first insertion"<<endl;
                cout<<"press 2 for last insertion"<<endl;
                cout<<"press 3 for after insertion"<<endl;
                cout<<"press 4 for before insertion"<<endl;
                cout<<"press 0 for return "<<endl;
                while(1)
                {
                    cin>>r;
                    if(r==1)
                        f_insert();
                    else if(r==2)
                        l_insert();
                    else if(r==3)
                        a_insert();
                    else if(r==4)
                        b_insert();
                    else if(r==0)
                        break;
                    else
                        cout<<"Please enter the right key"<<endl;
                }
            }
            else if(q==2)
            {
                cout<<"press 1 for first deletion"<<endl;
                cout<<"press 2 for last deletion"<<endl;
                cout<<"press 3 for given item deletion"<<endl;
                cout<<"press 4 for after deletion"<<endl;
                cout<<"press 5 for before deletion"<<endl;
                cout<<"press 0 for return "<<endl;
                while(1)
                {
                    cin>>r;
                    if(r==1)
                        f_del();
                    else if(r==2)
                        l_del();
                    else if(r==3)
                        given_dlt();
                    else if(r==4)
                        after_dlt();
                    else if(r==5)
                        before_dlt();
                    else if(r==0)
                        break;
                    else
                        cout<<"Please enter the right key"<<endl;

                }
            }
        }
        else if(p==0)
            break;
        else
            cout<<"Please enter the right key"<<endl;
    }
}
