#include<stdio.h>
#include<math.h>

main()
{
    int i,dif=100,sum=0,x,y;
    for(i=0;i<10;i++)
    {
        scanf("%d",&x);
        y=fabs(100-(sum+x));
        if(y<=dif)
        {
            dif=y;
            sum+=x;
        }
        else
        {
            break;
        }
    }
    printf("%d\n",sum);
}
