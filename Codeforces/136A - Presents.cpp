#include<stdio.h>

main()
{
    int n,i,x;
    scanf("%d",&n);
    int out[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        out[x-1]=i+1;
    }
    for(i=0;i<n;i++)
    {
        if(i==n-1)
        {
            printf("%d",out[i]);
        }
        else
        {
            printf("%d ",out[i]);
        }
    }
    printf("\n");
}
