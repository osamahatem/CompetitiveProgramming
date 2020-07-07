#include<stdio.h>
#include<math.h>

main()
{
    int n,i,sa=0,sg=0;
    scanf("%d",&n);
    int a[n],g[n];
    char out[n];
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a[i],&g[i]);
        if(i==0)
        {
            if(a[i]<=g[i])
            {
                sa+=a[i];
                out[i]='A';
            }
            else
            {
                sg+=g[i];
                out[i]='G';
            }
        }
        else
        {
            if(fabs(sa+a[i]-sg)<=500)
            {
                sa+=a[i];
                out[i]='A';
            }
            else if(fabs(sg+g[i]-sa)<=500)
            {
                sg+=g[i];
                out[i]='G';
            }
            else
            {
                if(sa<=sg)
                {
                    sa+=a[i];
                    out[i]='A';
                }
                else
                {
                    sg+=g[i];
                    out[i]='G';
                }
            }
        }
    }
    if(fabs(sa-sg)>500)
    {
        printf("-1");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            printf("%c",out[i]);
        }
    }
    printf("\n");
}
