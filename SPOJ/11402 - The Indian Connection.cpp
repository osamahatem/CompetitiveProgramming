#include<cstdio>

long long power(int x,int y)
{
    long long res=1;
    while(y--)
    {
        res*=x;
    }
    return res;
}

main()
{
    char c;
    int t,n,i;
    long long k,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld",&n,&k);
        c='M';
        for(i=1;i<n;i++)
        {
            p=power(2,i-1);
            if(k<=p)
            {
                if(c=='M')
                {
                    c='M';
                }
                else
                {
                    c='F';
                }
            }
            else
            {
                if(c=='M')
                {
                    c='F';
                }
                else
                {
                    c='M';
                }
            }
            k/=2;
        }
        if(c=='M')
        {
            printf("Male\n");
        }
        else
        {
            printf("Female\n");
        }
    }
    return 0;
}
