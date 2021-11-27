#include<bits/stdc++.h>
#include<string>

using namespace std;
int ara[1000],n,i;
void travarse()
{
    for(i=0;i<n;i++)
    {
        printf("%d ",ara[i]);
    }
    printf("\n");
}
void sorted()
{
    int t;
    for(i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
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
void binaryserch(int s)
{
    int first,last,middle;
    first=0;
    last=n-1;
    middle=(first+last)/2;
    while(first<=last)
    {
        if(ara[middle]<s)
            first=middle+1;
        else if(ara[middle]==s)
        {
            printf("%d",middle+1);
            break;
        }
        else
            last=middle-1;
        middle=(first+last)/2;
    }
    if(first>last)
    {
        printf("Data not found\n");
    }
}


int main()
{
    int i,first,last,middle,serch;
    cin>>n;
    for(i=0; i<n; i++)
    {
        ara[i]=rand()%10;
    }
    travarse();
    sorted();
    cin>>serch;
    binaryserch(serch);

    return 0;

}

