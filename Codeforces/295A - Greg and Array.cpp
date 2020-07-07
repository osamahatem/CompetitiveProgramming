#include<cstdio>

using namespace std;

main()
{
    int n,m,k,i,j;
    scanf("%d%d%d",&n,&m,&k);
    long long arr[n];
    int l[m],r[m],d[m],x[k],y[k];
    for(i=0;i<n;i++)
    {
        scanf("%I64d",&arr[i]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&l[i],&r[i],&d[i]);
    }
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
    }
    for(i=0;i<n;i++)
    {
        if(i==n-1)
        {
            printf("%I64d\n",arr[i]);
        }
        else
        {
            printf("%I64d ",arr[i]);
        }
    }
    return 0;
}
