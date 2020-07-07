#include<stdio.h>

main()
{
    int n,c,x=0,y=0,z=0,i;
    scanf("%d",&n);
    for(c=0;c<n;c++)
    {
        scanf("%d",&i);
        x+=i;
        scanf("%d",&i);
        y+=i;
        scanf("%d",&i);
        z+=i;
    }
    if(x==0 && y==0 && z==0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
