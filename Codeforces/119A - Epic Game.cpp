#include<stdio.h>

main()
{
    int a,b,n,c1=1,c2,gcd;
    scanf("%d %d %d",&a,&b,&n);
    while(n>0)
    {
        if(c1%2!=0)
        {
            for(c2=1;c2<=n;c2++)
            {
                if(a%c2==0 && n%c2==0)
                {
                    gcd=c2;
                }
            }
            n=n-gcd;
        }
        else
        {
            for(c2=1;c2<=n;c2++)
            {
                if(b%c2==0 && n%c2==0)
                {
                    gcd=c2;
                }
            }
            n=n-gcd;
        }
        c1++;
    }
    if(c1%2==0)
    {
        printf("0\n");
    }
    else
    {
        printf("1\n");
    }
}
