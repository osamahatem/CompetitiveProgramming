#include<cstdio>
#include<map>

using namespace std;

main()
{
    long long t,T,x,y,n,N,cnt,c[100000];
    map<long long,long long> flag;
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        cnt=0;
        flag.clear();
        scanf("%lld%lld",&x,&N);
        for(n=0;n<N;n++)
        {
            scanf("%lld",&c[n]);
            flag[c[n]]++;
        }
        for(n=0;n<N;n++)
        {
            flag[c[n]]--;
            y=x-c[n];
            if(flag.count(y))
            {
                cnt+=flag[y];
            }
        }
        printf("%lld. %lld\n",t,cnt);
    }
    return 0;
}
