#include<stdio.h>

main()
{
    int n,i,x,heights[1001],maxh=0,num=0;
    scanf("%d",&n);
    for(i=0;i<1001;i++)
    {
        heights[i]=0;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        heights[x]++;
    }
    for(i=0;i<1001;i++)
    {
        if(heights[i]==0)
        {
            continue;
        }
        else if(heights[i]>maxh)
        {
            maxh=heights[i];
        }
        num++;
    }
    printf("%d %d\n",maxh,num);
}
