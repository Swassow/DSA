#include<bits/stdc++.h>

using namespace std;

class node
{
public:
    int info;
    node *link;
};
node *head = NULL, *tmp = NULL;
void cr(int a)
{
    node *st;
    st = new node;
    st->info = a;
    st->link = NULL;
    if(head==NULL)
    {
        head=st;
        tmp=st;
        return;
    }
    tmp->link = st;
    tmp = st;
}

void trav()
{
    node *str = head;

    while(str != NULL)
    {
        cout << str->info << " ";
        str = str->link;
    }

    cout << endl;
}
void f_del()
{
    head = head->link;
    cout << "First delete success" << endl;
    trav();
}
void l_del()
{
    node *str = head;
    node *temp = str->link;

    while(1)
    {


        if( temp->link == NULL)
        {
            str->link = NULL;
            cout << "Last delete success" << endl;
            break;
        }

        str = str->link;
        temp = temp->link;
    }
    trav();

}
void g_del()
{
    node *str = head;
    node *tem;

    int a;

    cout << "Enter the value to delete:" ;
    cin >> a;

    while(1)
    {
        if(str->info == a)
        {
            if( str == head)
            {
                f_del();
            }

            else if( str->link == NULL)
            {
                l_del();
            }

            tem->link = str->link;
            cout << "Given item deletion successful." << endl;
            break;

        }
        tem = str;
        str = str->link;

        if( str == NULL)
        {
            cout << "Given item not found in the list." << endl;
            return;
        }
    }
    trav();
}

void a_del()
{
    node *str = head;
    node *tem = str->link;

    int a;

    cout << "Enter the value after which deletion will occur:";
    cin >> a;

    while(str != NULL)
    {
        if(str->info == a)
        {
            if( str->link == NULL)
            {
                cout << "Deletion after " << str->info << " unsuccessful." << endl;
                break;
            }

            str->link = tem->link;
            cout << "Deletion successful." << endl;
            break;

        }

        str = str->link;
        if(str != NULL)tem = str->link;

        if( str == NULL)
        {
            cout << "Given item not found in the list." << endl;
            return;
        }
    }
    trav();
}

int main()
{
    int data,n,i,t,p;
    cout<<"Enter numbers of given item"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cr(rand()%10);
    }
    cout<<"Press 1 for traversing"<<endl;
    cout<<"Press 2 for first delete"<<endl;
    cout<<"Press 3 for last delete"<<endl;
    cout<<"Press 4 for given item delete"<<endl;
    cout<<"Press 5 for after deletion of a given item"<<endl;
    cout<<"Press 0 for close the program"<<endl;
    while(1)
    {
        cin>>p;
        if(p==1)
            trav();
        else if(p==2)
         f_del();
        else if(p==3)
            l_del();
        else if(p==4)
            g_del();
        else if(p==5)
            a_del();
        else if(p==0)
            break;

    }
}
