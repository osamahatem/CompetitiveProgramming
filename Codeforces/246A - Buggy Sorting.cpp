#include<stdio.h>

main()
{
    int n,i,x[50];
    scanf("%d",&n);
    for(i=0;i<50;i++)
    {
        x[i]=i+1;
    }
    if(n==1 || n==2)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d %d",x[n-1],x[n-2]);
        for(i=0;i<n-2;i++)
        {
            printf(" %d",x[i]);
        }
    }
    printf("\n");
}
