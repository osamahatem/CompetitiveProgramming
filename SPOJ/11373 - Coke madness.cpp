#include<cstdio>
#include<cmath>
#include<cstdlib>

using namespace std;

main()
{
    long long t,n,i,x,en,mini;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        en=0;
        mini=1;
        for(n;n>0;n--)
        {
            scanf("%lld",&x);
            en+=x;
            if(en<mini)
            {
                mini=en;
            }
        }
        if(mini<0)
        {
            x=abs(mini)+1;
            printf("Scenario #%lld: %lld\n",i,x);
        }
        else
        {
            printf("Scenario #%lld: 1\n",i);
        }
    }
    return 0;
}
