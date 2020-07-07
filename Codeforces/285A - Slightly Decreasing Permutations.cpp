#include<stdio.h>

main()
{
    int n,k,i=0,j=0,temp,x[100000];
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        x[i]=i+1;
    }
    if(k>n/2)
    {
        i=n-2;
        j=1;
        printf("%d",x[n-1]);
        while(j<k)
        {
            printf(" %d",x[i]);
            i--;
            j++;
        }
        for(i=0;i<n-k;i++)
        {
            printf(" %d",x[i]);
        }
        printf("\n");
    }
    else
    {
        i=0;
        j=0;
        while(j<k)
        {
            temp=x[i];
            x[i]=x[i+1];
            x[i+1]=temp;
            i+=2;
            j++;
        }
        printf("%d",x[0]);
        for(i=1;i<n;i++)
        {
            printf(" %d",x[i]);
        }
        printf("\n");
    }
}
