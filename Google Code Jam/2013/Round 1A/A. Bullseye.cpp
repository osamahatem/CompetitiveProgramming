#include<cstdio>

main()
{
    freopen("A. Bullseye.in","r",stdin);
    freopen("A. Bullseye.out","w",stdout);
    int t,T;
    long long r,p,area,c,inc;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        c=0;
        scanf("%lld%lld",&r,&p);
        area=(r+1)*(r+1)-r*r;
        inc=area;
        while(area<=p)
        {
            inc+=4;
            area+=inc;
            c++;
        }
        printf("Case #%d: %lld",t,c);
        if(t!=T)
        {
            printf("\n");
        }
    }
    return 0;
}
