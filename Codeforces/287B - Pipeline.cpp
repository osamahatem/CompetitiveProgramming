#include<stdio.h>

main()
{
    long long n,k,i,j=1,c=1;
    scanf("%I64d %I64d",&n,&k);
    for(i=k;i>=2;i--)
    {
        if(n-j<i-1)
        {
            i=n-j+2;
        }
        else
        {
            j+=i-1;
            if(j==n)
            {
                printf("%I64d\n",c);
                return 0;
            }
            c++;
        }
    }
    printf("-1\n");
    return 0;
}
