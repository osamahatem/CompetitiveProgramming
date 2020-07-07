#include<cstdio>

main()
{
    int n,x,y;
    scanf("%d",&n);
    for(n;n>0;n--)
    {
        scanf("%d%d",&x,&y);
        if(x==y || x-y==2)
        {
            if(x%2==0)
            {
                printf("%d\n",x+y);
            }
            else
            {
                printf("%d\n",x+y-1);
            }
        }
        else
        {
            printf("No Number\n");
        }
    }
    return 0;
}
