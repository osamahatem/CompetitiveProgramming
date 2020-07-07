#include<stdio.h>

main()
{
    int x;
    scanf("%d",&x);
    while(x!=42)
    {
        printf("%d\n",x);
        scanf("%d",&x);
    }
}
