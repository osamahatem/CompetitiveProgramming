#include<stdio.h>

main()
{
    int n,i;
    scanf("%d",&n);
    int input[n],evenness[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
        if(input[i]%2==0)
        {
            evenness[i]=0;
        }
        else
        {
            evenness[i]=1;
        }
    }
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            if(evenness[i]!=evenness[i+1] && evenness[i]!=evenness[i+2])
            {
                printf("%d\n",i+1);
                break;
            }
        }
        else if(i==n-1)
        {
            if(evenness[i]!=evenness[i-1] && evenness[i]!=evenness[i-2])
            {
                printf("%d\n",i+1);
                break;
            }
        }
        else if(evenness[i]!=evenness[i-1] && evenness[i]!=evenness[i+1])
        {
            printf("%d\n",i+1);
            break;
        }
    }
}
