#include<cstdio>
#include<cstdlib>

main()
{
    int n,d,h[1000],i,j,c=0;
    scanf("%d%d",&n,&d);
    for(i=0;i<n;i++)
    {
        scanf("%d",&h[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                continue;
            }
            if(abs(h[i]-h[j])<=d)
            {
                c++;
            }
        }
    }
    printf("%d\n",c);
    return 0;
}
