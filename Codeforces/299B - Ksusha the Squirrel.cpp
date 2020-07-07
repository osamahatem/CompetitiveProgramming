#include<cstdio>

main()
{
    int n,k,i,c=0;
    bool flag=0;
    char road[300010];
    scanf("%d%d\n%s",&n,&k,road);
    for(i=0;i<n;i++)
    {
        if(road[i]=='.')
        {
            c=0;
        }
        else
        {
            c++;
            if(c==k)
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}
