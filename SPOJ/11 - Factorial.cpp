#include<cstdio>

main()
{
    long long t,n,sum;
    scanf("%lld",&t);
    for(t;t>0;t--)
    {
        sum=0;
        scanf("%lld",&n);
        while(n!=0)
        {
            n/=5;
            sum+=n;
        }
        printf("%lld\n",sum);
    }
}
