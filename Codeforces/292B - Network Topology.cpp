#include<cstdio>

main()
{
    int n,m,i,x,y,c1=0,c2=0,c3=0;
    scanf("%d%d",&n,&m);
    int c[n];
    for(i=0;i<n;i++)
    {
        c[i]=0;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        c[x-1]++;
        c[y-1]++;
    }
    for(i=0;i<n;i++)
    {
        if(c[i]==1)
        {
            c1++;
        }
        else if(c[i]==2)
        {
            c2++;
        }
        else
        {
            c3++;
        }
    }
    if(c2==n)
    {
        printf("ring topology\n");
    }
    else if(c1==2 && c1+c2==n)
    {
        printf("bus topology\n");
    }
    else if(c1==n-1 && c3+c1==n)
    {
        printf("star topology\n");
    }
    else
    {
        printf("unknown topology\n");
    }
    return 0;
}
