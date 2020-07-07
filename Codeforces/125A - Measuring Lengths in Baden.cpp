#include<stdio.h>

main()
{
    int n,a,b;
    scanf("%d",&n);
    b=n/3;
    n-=b*3;
    if(n==2)
    {
        b++;
    }
    a=b/12;
    b-=a*12;
    printf("%d %d\n",a,b);
}
