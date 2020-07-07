#include<stdio.h>

main()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    if(a+b>=n)
    {
        printf("%d\n",n-a);
    }
    else
    {
        printf("%d\n",b+1);
    }
    return 0;
}
