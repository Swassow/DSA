#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a1[1000], a2[1000],n;
    cout<<"Enter the number of first array"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        a1[i]=rand()%10;
    }
    cout<<"The first array is: ";
    for(int i=0;i<n;i++)
    {

        cout<<a1[i]<< " ";
    }
    int t,j,k;
    //Insertion sort
    for(int j=1; j<n; j++)
    {
        t=a1[j];
        k=j-1;
        while(k>=0 && a1[k]>t)
        {
            a1[k+1]=a1[k];
            k--;
        }
        a1[k+1]=t;
    }

    cout<<"\nThe sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<a1[i]<< " ";
    }
    int num,m;
    cout<<"\nEnter the number of second element:";
    cin>>num;
    for(int i=0;i<num;i++)
    {
        a2[i]=rand()%10;
    }
    cout<<"\nThe second array is: ";
    for(int i=0;i<num;i++)
    {
        cout<<a2[i]<< " ";
    }
    //selection sort
    for (int i = 0; i < num-1; i++)
    {
        m=i;
        for (j = i+1; j < num; j++)
        if (a2[j] < a2[m])
            m = j;

        int temp=a2[m];
        a2[m]=a2[i];
        a2[i]=temp;
    }
    cout<<"\nThe sorted array is: ";
    for(int i=0;i<num;i++)
    {
        cout<<a2[i]<< " ";
    }
}
