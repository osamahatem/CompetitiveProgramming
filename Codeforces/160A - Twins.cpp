#include<stdio.h>

main()
{
    int n,i,j,temp,sum=0,sum2=0,c=0;
    scanf("%d",&n);
    int val[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&val[i]);
        sum+=val[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(val[j]>val[j+1])
            {
                temp=val[j+1];
                val[j+1]=val[j];
                val[j]=temp;
            }
        }
    }
    i=n-1;
    while(sum2<=sum)
    {
        sum2+=val[i];
        sum-=val[i];
        c++;
        i--;
    }
    printf("%d\n",c);
}
