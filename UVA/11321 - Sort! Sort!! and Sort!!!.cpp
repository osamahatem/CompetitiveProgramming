#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int m;

bool comp(const int& a,const int& b)
{
    if(a%m!=b%m)
    {
        return a%m<b%m;
    }
    if(abs(a%2)==1 && abs(b%2)==1)
    {
        return a>b;
    }
    if(a%2==0 && b%2==0)
    {
        return a<b;
    }
    return (abs(a%2)==1);
}

main()
{
    int n,i;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0 && m==0)
        {
            break;
        }
        int x[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
        }
        sort(x,x+n,comp);
        printf("%d %d\n",n,m);
        for(i=0;i<n;i++)
        {
            printf("%d\n",x[i]);
        }
    }
    printf("0 0\n");
    return 0;
}
