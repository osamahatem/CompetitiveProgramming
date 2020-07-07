#include<stdio.h>

main()
{
    int x=0,n,i;
    char c[4];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",c);
        if(c[1] == '+')
        {
            x++;
        }
        else
        {
            x--;
        }
    }
    printf("%d\n",x);
}
