#include<stdio.h>

main()
{
    int n,i,j,x,a,t,len=1,sum=0,sequence[200000];
    double avg;
    sequence[0]=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d %d",&a,&x);
            for(j=0;j<a;j++)
            {
                sequence[j]+=x;
            }
            sum+=x*a;
            avg=(double)sum/(double)len;
            printf("%lf\n",avg);
        }
        else if(t==2)
        {
            scanf("%d",&x);
            sequence[len]=x;
            len++;
            sum+=x;
            avg=(double)sum/(double)len;
            printf("%lf\n",avg);
        }
        else if(t==3)
        {
            len--;
            sum-=sequence[len];
            sequence[len]=0;
            avg=(double)sum/(double)len;
            printf("%lf\n",avg);
        }
    }
}
