#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x1,x2,x3,x4,a,b,c;
    cin>>x1>>x2>>x3>>x4;
    if(x4>=x1&&x4>=x2&&x4>=x3)
    {
        b=((x1+x3)-x2)/2;
        a=x1-b;
        c=x3-b;
        cout<<a<<" "<<b<<" "<<c;
    }
    else if(x3>=x1&&x3>=x2&&x3>=x4)
    {
        b=((x1+x4)-x2)/2;
        a=x1-b;
        c=x4-b;
        cout<<a<<" "<<b<<" "<<c;
    }

    else if(x2>=x1&&x2>=x3&&x2>=x4)
    {
        b=((x1+x3)-x4)/2;
        a=x1-b;
        c=x3-b;
        cout<<a<<" "<<b<<" "<<c;
    }
    else
    {
        b=((x4+x3)-x2)/2;
        a=x4-b;
        c=x3-b;
        cout<<a<<" "<<b<<" "<<c;
    }

}
