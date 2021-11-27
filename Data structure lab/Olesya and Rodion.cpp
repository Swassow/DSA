#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,m,i,c=0;
    cin>>n>>m;
    long long int ara[m+10];
    for(i=0; i<m; i++)
    {
        cin>>ara[i];
    }
    c=ara[0]-1;
    for(i=0;i<m-1;i++)
    {
       if(ara[i+1]<ara[i])
            c=c+(n-ara[i]+ara[i+1]);
       else if(ara[i+1]>ara[i])
        c=c+(ara[i+1]-ara[i]);
    }
    cout<<c;

}

