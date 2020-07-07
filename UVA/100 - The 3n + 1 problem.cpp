#include<cstdio>
#include<algorithm>

using namespace std;

long long i,j;

long long maxl(long long a,long long b)
{
    long long maxi=0,c,x;
    for(;a<=b;a++)
    {
        c=1;
        x=a;
        while(x!=1)
        {
            c++;
            if(x%2==1)
            {
                x=3*x+1;
            }
            else
            {
                x=x/2;
            }
        }
        if(c>maxi)
        {
            maxi=c;
        }
    }
    return maxi;
}

main()
{
    long long m,x,y;
    while(scanf("%lld%lld",&i,&j)!=EOF)
    {
        x=min(i,j);
        y=max(i,j);
        m=maxl(x,y);
        printf("%lld %lld %lld\n",i,j,m);
    }
    return 0;
}
