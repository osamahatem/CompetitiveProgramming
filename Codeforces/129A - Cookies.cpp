#include<stdio.h>

main()
{
    int n,i,c=0,sum=0;
    scanf("%d",&n);
    int x[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
        sum+=x[i];
    }
    for(i=0;i<n;i++)
    {
        if(sum%2==0)
        {
            if(x[i]%2==0)
            {
                c++;
            }
        }
        else
        {
            if(x[i]%2==1)
            {
                c++;
            }
        }
    }
    printf("%d\n",c);
}
