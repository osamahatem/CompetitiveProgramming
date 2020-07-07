#include<cstdio>

main()
{
    int n,i;
    scanf("%d",&n);
    if(n%2==1)
    {
        printf("-1");
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            if(i%2==1)
            {
                printf("%d",i+1);
            }
            else
            {
                printf("%d",i-1);
            }
            if(i!=n)
            {
                printf(" ");
            }
        }
    }
    printf("\n");
    return 0;
}
