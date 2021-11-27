#include<bits/stdc++.h>

using namespace std;
int ara[100],n,i;

void travarse()
{
    for(i=0; i<n; i++)
    {
        printf("%d ",ara[i]);
    }
    printf("\n");
}
void insart(int item,int pos)
{
    for(i=n-1; i>=pos; i--)
    {
        ara[i+1]=ara[i];

    }
    ara[pos]=item;
    n++;
    travarse();
    printf("\n");
}
void delet(int pos)
{
    for(i=pos+1; i<n; i++)
    {
        ara[i-1]=ara[i];
    }
    n--;
    travarse();
    printf("\n");
}
int serch(int data)
{
    for(i=0; i<n; i++)
    {
        if(ara[i]==data)
        {
            printf("%d",i+1);
            return 0;
        }
    }
    printf("Data not found\n");
    return 0;
}

int main()
{
    int item,pos,j;
    cin>>n;
    for(i=0; i<n; i++)
    {
        ara[i]=rand()%10;
    }
    while(1)
    {
        cin>>j;
           if(j==1)
        {
            travarse();
        }
        else if(j==2)
        {
            cin>>pos>>item;
            insart(item,pos);
        }
        else if(j==3)
        {
            cin>>pos;
            delet(pos);
        }
        else if(j==4)
        {
            cin>>item;
            serch(item);
        }
        else if(j==0)
        {
            break;
        }
    }



}
