#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

main()
{
    int n,m,d,i,j,y,t,c=0;
    scanf("%d%d%d",&n,&m,&d);
    int x[n*m];
    y=n*m;
    for(i=0;i<y;i++)
    {
        scanf("%d",&x[i]);
    }
    sort(x,x+n*m);
    j=y/2;
    for(i=0;i<y;i++)
    {
        t=fabs(x[i]-x[j]);
        if(t%d==0)
        {
            c+=t/d;
        }
        else
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",c);
    return 0;
}
