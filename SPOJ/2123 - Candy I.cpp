#include<stdio.h>
#include<math.h>

main()
{
    int n,i,sum,avg,moves;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)
        {
            break;
        }
        sum=0;
        moves=0;
        int x[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            sum+=x[i];
        }
        if(sum%n==0)
        {
            avg=sum/n;
            for(i=0;i<n;i++)
            {
                if(x[i]<avg)
                {
                    moves+=fabs(avg-x[i]);
                }
            }
            printf("%d\n",moves);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
