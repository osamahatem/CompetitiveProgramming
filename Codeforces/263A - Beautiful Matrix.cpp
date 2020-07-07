#include<stdio.h>
#include<math.h>

main()
{
    int i,j,r,c,x;
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            scanf("%d",&x);
            if(x==1)
            {
                r=i;
                c=j;
            }
        }
    }
    x=fabs(r-3)+fabs(c-3);
    printf("%d\n",x);
}
