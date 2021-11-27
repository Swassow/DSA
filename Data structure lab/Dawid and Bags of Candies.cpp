#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,t=4,c=0;
    while(t--)
    {
        cin>>n;
        c+=n;
    }
    if(c%2==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
