#include<cstdio>

main()
{
    int n,m,i;
    long long time=0,moment[100000],c,t,j=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%I64d%I64d",&c,&t);
        time+=c*t;
        moment[i]=time;
    }
    for(i=0;i<m;i++)
    {
        scanf("%I64d",&time);
        while(time>moment[j])
        {
            j++;
        }
        printf("%I64d\n",j+1);
    }
    return 0;
}
