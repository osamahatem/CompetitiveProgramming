#include<cstdio>
#include<algorithm>

using namespace std;

main()
{
    long long x[3];
    while(1)
    {
        scanf("%lld %lld %lld",&x[0],&x[1],&x[2]);
        if(x[0]==0 && x[1]==0 && x[2]==0)
        {
            break;
        }
        sort(x,x+3);
        if(x[0]*x[0]+x[1]*x[1]==x[2]*x[2])
        {
            printf("right\n");
        }
        else
        {
            printf("wrong\n");
        }
    }
    return 0;
}
