#include<stdio.h>

main()
{
    int n,i,p[7];
    scanf("%d",&n);
    for(i=0;i<7;i++)
    {
        scanf("%d",&p[i]);
    }
    i=0;
    while(n>0)
    {
        if(i==7)
        {
            i=0;
        }
        n-=p[i];
        i++;
    }
    printf("%d\n",i);
}
