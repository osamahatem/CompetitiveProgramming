#include<cstdio>
#include<cmath>

int s(long long x)
{
    int sum=0;
    while(x!=0)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}

main()
{
    long long n,x,y,i;
    scanf("%I64d",&n);
    x=sqrt(n);
    i=x;
    y=x*x+s(x)*x-n;
    while(i>0)
    {
        if(y==0)
        {
            printf("%I64d\n",i);
            return 0;
        }
        i--;
        y=i*i+s(i)*i-n;
    }
    printf("-1\n");
    return 0;
}
