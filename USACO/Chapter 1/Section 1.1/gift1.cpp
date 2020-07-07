/*
ID: 19semse1
PROG: gift1
LANG: C++
*/

#include<cstdio>
#include<cstring>

using namespace std;

main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    int n,i,j,k,idx,m,g;
    scanf("%d\n",&n);
    char fr[n][20],x[20];
    int sum[n];
    for(i=0;i<n;i++)
    {
        sum[i]=0;
        scanf("%s",fr[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%s",x);
        for(j=0;j<n;j++)
        {
            if(!strcmp(x,fr[j]))
            {
                idx=j;
                break;
            }
        }
        scanf("%d%d\n",&m,&g);
        for(k=0;k<g;k++)
        {
            scanf("%s",x);
            for(j=0;j<n;j++)
            {
                if(!strcmp(x,fr[j]))
                {
                    sum[j]+=m/g;
                }
            }
        }
        if(g==0)
        {
            sum[idx]+=m;
        }
        else
        {
            sum[idx]-=(m-m%g);
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%s %d\n",fr[i],sum[i]);
    }
    return 0;
}
