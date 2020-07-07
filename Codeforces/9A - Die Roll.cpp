#include<cstdio>
#include<algorithm>

using namespace std;

int gcd(int x, int y)
{
    if(y==0)
    {
        return x;
    }
    x=x%y;
     return gcd(y,x);
}

main()
{
    int a,b,p;
    scanf("%d%d",&a,&b);
    p=6-max(a,b)+1;
    printf("%d/%d\n",p/gcd(p,6),6/gcd(p,6));
    return 0;
}
