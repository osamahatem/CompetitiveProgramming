#include<cstdio>
#include<algorithm>

using namespace std;

main()
{
    int t,n,i,sum;
    scanf("%d",&t);
    for(t;t>0;t--)
    {
        sum=0;
        scanf("%d",&n);
        int x[2][n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[0][i]);
        }
        sort(x[0],x[0]+n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[1][i]);
        }
        sort(x[1],x[1]+n);
        for(i=0;i<n;i++)
        {
            sum+=x[0][i]*x[1][i];
        }
        printf("%d\n",sum);
    }
    return 0;
}
