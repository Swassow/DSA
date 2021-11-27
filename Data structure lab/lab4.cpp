#include<bits/stdc++.h>

using namespace std;

int n1,n2,i,j;
int ara[100],ara1[100];

void travarse(int n,int *p)
{
    for(i=0;i<n;i++)
    {
        printf("%d ",p[i]);
    }
    printf("\n");
}

void insertation_sort(int n,int *p)
{
    int t;
    for(i=0;i<n;i++)
    {
        t=p[i];
        j=i-1;
        while(j>=0&&p[j]>t)
        {
            p[j+1]=p[j];
            j--;
        }
        p[j+1]=t;
    }
    travarse(n,p);
}
void selection_sort(int n,int *q)
{
    int m,t;
    for(i=0;i<n-1;i++)
    {
        m=i;
        for(j=i+1;j<n;j++)
        {
            if(q[j]<q[m])
                m=j;
        }
        if(m!=i)
        {
            t=q[m];
            q[m]=q[j];
            q[j]=t;
        }
    }
    travarse(n,q);
}

int main()
{
    int i,j,m,t;

    cin>>n1;
    for(i=0;i<n1;i++)
    {
        ara[i]=rand()%10;
    }
    travarse(n1,ara);
    insertation_sort(n1,ara);
    cin>>n2;
    for(i=0;i<n2;i++)
    {
        ara[i]=rand()%10;
    }
    travarse(n2,ara1);
    selection_sort(n2,ara1);
}
