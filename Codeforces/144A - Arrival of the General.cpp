#include<stdio.h>

main()
{
    int n,i,maxi=0,mini=100,imin=0,imax=0,x;
    scanf("%d",&n);
    int h[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&h[i]);
        if(h[i]>maxi)
        {
            maxi=h[i];
            imax=i;
        }
        if(h[i]<=mini)
        {
            mini=h[i];
            imin=i;
        }
    }
    if(imax<imin)
    {
        x=imax+(n-1-imin);
    }
    else
    {
        x=imax+(n-1-imin)-1;
    }
    printf("%d\n",x);
}
