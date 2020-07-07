#include<stdio.h>

main()
{
    int n,x,i,m[3]={0,0,0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        m[i%3]+=x;
    }
    if(m[0]>m[1] && m[0]>m[2])
    {
        printf("chest\n");
    }
    else if(m[1]>m[0] && m[1]>m[2])
    {
        printf("biceps\n");
    }
    else
    {
        printf("back\n");
    }
}
