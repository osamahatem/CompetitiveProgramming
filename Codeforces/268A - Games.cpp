#include<stdio.h>

main()
{
    int n,i,j,c=0;
    scanf("%d",&n);
    int h[n],a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&h[i],&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(h[i]==a[j])
            {
                c++;
            }
        }
    }
    printf("%d\n",c);
}
