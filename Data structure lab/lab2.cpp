#include<bits/stdc++.h>

using namespace std;

int ara[1000],n,i,j;

void travarse()
{
    for(i=0; i<n; i++)
    {
        printf("%d ",ara[i]);
    }
    printf("\n");
}
void sorting()
{
    int t;
    printf("After sorting\n");
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(ara[j]>ara[j+1])
            {
                t=ara[j];
                ara[j]=ara[j+1];
                ara[j+1]=t;
            }
        }
    }
    travarse();
}
void binaryserch(int data)
{
    int lb,ub,mid;
    lb=0;
    ub=n-1;
    mid=(lb+ub)/2;
    while(lb<=ub)
    {
        if(ara[mid]==data)
        {
            printf("The index of the element is %d",mid+1);
            break;
        }
        else if(ara[mid]<data)
        {
            lb=mid+1;
        }
        else
            ub=mid-1;
        mid=(lb+ub)/2;
    }
    if(lb>ub)
        printf("Data not found\n");
}

int main()
{
    int data,t;
    printf("Enter numbers of element\n");
    cin>>n;
    for(i=0; i<n; i++)
    {
        ara[i]=rand()%10;
    }
    printf("press 1 for travarsing\n");
    printf("press 2 for sorting\n");
    printf("press 3 for serching\n");
    printf("press 0 for ending this programme\n");
    while(1)
    {
        cin>>t;
        if(t==1)
        {
            travarse();
        }
        else if(t==2)
        {
            sorting();
        }
        else if(t==3)
        {
            printf("Give data which index u want to search\n");
            cin>>data;
            binaryserch(data);
        }
        else if(t==0)
        {
            break;
        }

    }

}
