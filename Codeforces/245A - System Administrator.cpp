#include<stdio.h>

main()
{
    int n,t,x,y,a[2]={0,0},b[2]={0,0};
    scanf("%d",&n);
    for(n;n>0;n--)
    {
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d %d",&x,&y);
            a[0]+=x;
            a[1]+=y;
        }
        else
        {
            scanf("%d %d",&x,&y);
            b[0]+=x;
            b[1]+=y;
        }
    }
    if(a[0]<a[1])
    {
        printf("DEAD\n");
    }
    else
    {
        printf("LIVE\n");
    }
    if(b[0]<b[1])
    {
        printf("DEAD\n");
    }
    else
    {
        printf("LIVE\n");
    }
}
