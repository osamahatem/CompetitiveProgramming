#include<cstdio>
#include<algorithm>
#include<cstdlib>

using namespace std;

bool cmp(int a, int b)
{
    return a>b;
}

main()
{
    int n,len,i,j,sum=0,change=0,x[200];
    scanf("%d",&n);
    len=2*n-1;
    for(i=0;i<len;i++)
    {
        scanf("%d",&x[i]);
        sum+=x[i];
    }
    sort(x,x+len,cmp);
    for(i=0;i<=len-n;i++)
    {
        for(j=i;j<n+i;j++)
        {
            x[j]*=-1;
            change+=x[j];
        }
        if(change>0)
        {
            sum+=2*change;
        }
        else
        {
            for(j=i;j<n+i;j++)
            {
                x[j]*=-1;
            }
        }
        change=0;
    }
    printf("%d\n",sum);
    return 0;
}
