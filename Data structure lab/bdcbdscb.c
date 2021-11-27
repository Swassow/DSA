#include<stdio.h>

int main()
{
    int n,p;
    scanf("%d",&n);
    p=__builtin_popcount(n);
    printf("%d",p);

}
