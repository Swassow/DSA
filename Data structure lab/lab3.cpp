#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int info;
    node *link;
};

node *head=NULL;
node *tmp=NULL;

void creation(int item)
{
    node *ptr;
    ptr=new node();
    ptr->info=item;
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
            cout<<srt->info;
            break;
        }
    }
    cout<<"\n";
}

void first_insert()
{
    int item;
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
    cin>>item;
    node *srt;
    node *ptr;
    ptr=new node();
    ptr->info=item;
    for(srt=head; ;)
    {
        if(srt->link==NULL)
        {
            srt->link=ptr;
            break;
        }
        else
            srt=srt->link;
    }
    travarse();
}

void before_insert()
{
    int s_item,data;
    cin>>s_item;
    node *srt;
    for(srt=head; ;)
    {
        if(srt->info==s_item)
        {
            if(srt==head)
                first_insert();
            else
            {
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
            cout<<"Data Not Found.";
            return;
        }

    }
    travarse();
}
void after_insert()
{
    int s_item,data;
    cin>>s_item;
    node *srt;
    for(srt=head; ;)
    {
        if(srt->info==s_item)
        {
            if(srt->link==NULL)
                last_insert();
            else
            {
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
            srt=srt->link;
        if(srt==NULL)
        {
            cout<<"Data Not Found.";
            return;
        }

    }
    travarse();

}
int main()
{
    int n,item,i,t;
    cout<<"Number of elemnts:"<<endl;
    cin>>n;
    cout<<"Elements:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>item;
        creation(item);
    }
    cout<<"Press 1 for travarsing"<<endl;
    cout<<"Press 2 for First insertion"<<endl;
    cout<<"Press 3 for last insertion"<<endl;
    cout<<"Press 4 for before insertion"<<endl;
    cout<<"Press 5 for after insertion"<<endl;
    cout<<"Press 0 for close the program"<<endl;
    while(1)
    {
        cin>>t;
        if(t==1)
            travarse();
        else if(t==2)
            first_insert();
        else if(t==3)
            last_insert();
        else if(t==4)
            before_insert();
        else if(t==5)
            after_insert();
        else if(t==0)
            break;
        else
            cout<<"press the right key";
    }
}
