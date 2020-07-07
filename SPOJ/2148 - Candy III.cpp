#include<stdio.h>

main()
{
    long long t,n,i,k,sum;
    scanf("%lld",&t);
    for(t;t>0;t--)
    {
        scanf("%lld",&n);
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&k);
            sum+=k%n;
        }
        if(sum%n==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
