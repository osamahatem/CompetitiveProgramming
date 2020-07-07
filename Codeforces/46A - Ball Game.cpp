#include<stdio.h>

main()
{
    int n,i,c=1;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        c+=i;
        if(c>n)
        {
            c-=n;
        }
        if(i==n)
        {
            printf("%d",c);
        }
        else
        {
            printf("%d ",c);
        }
    }
    printf("\n");
}
