#include<cstdio>

using namespace std;

main()
{
    int n,i,c[1000],x;
    for(i=0;i<1000;i++)
    {
        c[i]=0;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        c[x-1]++;
    }
    for(i=0;i<1000;i++)
    {
        if(c[i]>(n+1)/2)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
