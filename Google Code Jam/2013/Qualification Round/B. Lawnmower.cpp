#include<cstdio>

using namespace std;

int a[100][100];

bool check(int x, int n, int m, int e, int f)
{
    int i,flagx=1,flagy=1;
    for(i=0;i<n;i++)
    {
        if(a[i][f]>x)
        {
            flagx=0;
        }
    }
    for(i=0;i<m;i++)
    {
        if(a[e][i]>x)
        {
            flagy=0;
        }
    }
    return flagx||flagy;
}

main()
{
    freopen("B. Lawnmower.in","r",stdin);
    freopen("B. Lawnmower.out","w",stdout);
    int t,n,m,i,j,c,flag,maxi;
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        flag=1;
        maxi=1;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]>maxi)
                {
                    maxi=a[i][j];
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]<maxi && flag)
                {
                    flag=check(a[i][j],n,m,i,j);
                }
            }
        }
        if(flag)
        {
            printf("Case #%d: YES",c);
        }
        else if(!flag)
        {
            printf("Case #%d: NO",c);
        }
        if(c!=t)
        {
            printf("\n");
        }
    }
    return 0;
}
