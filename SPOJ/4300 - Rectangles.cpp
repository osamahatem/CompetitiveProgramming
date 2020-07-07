#include<stdio.h>

main()
{
    int n,i,j,c=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n/i;j++)
        {
            c++;
        }
    }
printf("%d",c);
}
