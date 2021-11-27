#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int info;
    node *link;
};
node *head=NULL,*tmp=NULL;
int s_item;
creation(int item)
{
    node *ptr;
    ptr=new node();
    ptr->info=item;
    ptr->link=NULL;
    if(head == NULL)
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
void traverse()
{
    node *x=head;
    while(x!=NULL)
    {
        cout<<x->info<<" ";
        x=x->link;
    }
    // cout<<x->info<<endl;
}
void first_delete()
{
    head=head->link;

    printf("\n");
    traverse();
}
void last_delete()
{
    node *x=head,*t=NULL;
    while(x->link!=NULL)
    {
        t=x;
        x=x->link;
    }
    t->link=NULL;
    printf("\n");
    traverse();
}
void given_delete()
{
    int m=114646465;
    cin>>s_item;
    node *x=head,*t=head;
    for(;;)
    {
        if(x->info==s_item)
        {
            if(x->link==head)
            {
                first_delete();
                m=0;
                break;
            }
            else if(x->link==NULL)
            {
                last_delete();
                m=0;
                break;
            }
            else
            {
                t->link=x->link;
                m=0;
                break;
            }
        }
        else
        {
            t=x;
            x=x->link;
            if(x==NULL)break;
        }
    }
    if(m!=0)printf("Item not found *_*\n");
    traverse();
}
void after_delete()
{
    int m=545489;
    cin>>s_item;
    node *x=head,*t=head;
    for(;;)
    {
        if(x->info==s_item)
        {
            if(x->link->link==NULL)
            {
                last_delete();m=0;
                break;
            }
            else
            {
                x->link=x->link->link;
                m=0;
                break;
            }
        }
        else
        {
            x=x->link;
            if(x==NULL)break;
        }
    }
    if(m!=0)printf("Item Not Found *-*\n");
    traverse();
}
void before_delete()
{
    int m=545489;
    cin>>s_item;
    node *x=head,*t=NULL,*prev=NULL;
    for(;;)
    {
        if(x->info==s_item)
        {
            if(t==head)
            {
                first_delete();m=0;
                break;
            }
            else
            {
                prev->link=x;
                m=0;break;
            }
        }
        else
        {
            prev=t;
            t=x;
            x=x->link;
            if(x==NULL)break;
        }
    }
    if(m!=0)printf("Item Not Found *-*\n");
    traverse();
}
int main()
{
    printf("Enter the number of nodes : ");
    int n,z;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        z=rand()%10;
        creation(z);
    }
    traverse();
    while(1)
    {
        int k;
        printf("\nPress  1 for traversing \n2 for first delete\n3 for last delete\n4 for given item delete\n5 for after a given item delete\n6 for before a given item delete\n0 to exit: ");
        cin>>k;
        if(k==0)
        {
            break;
        }
        else if(k==1)
        {
            traverse();
        }
        else if(k==2)
        {
            first_delete();
        }
        else if(k==3)
        {
            last_delete();
        }
        else if(k==4)
        {
            printf("Enter an item you want to delete : ");
            given_delete();
            cout<<endl;
        }
        else if(k==5)
        {
            printf("Enter an item you want to delete an item after that : ");
            after_delete();
        }
        else if(k==6)
        {
            printf("Enter an item you want to delete an item before that : " );
            before_delete();
        }
    }
    return 0;
}
