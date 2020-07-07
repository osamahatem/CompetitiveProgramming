#include<stdio.h>

main()
{
    long long n,m,a,x,y;
    scanf("%I64d %I64d %I64d",&n,&m,&a);
    if(n==a)
    {
        x=1;
    }
    else if(n%a==0)
    {
        x=n/a;
    }
    else
    {
        x=n/a+1;
    }
    if(m==a)
    {
        y=1;
    }
    else if(m%a==0)
    {
        y=m/a;
    }
    else
    {
        y=m/a+1;
    }
    printf("%I64d\n",x*y);
}
