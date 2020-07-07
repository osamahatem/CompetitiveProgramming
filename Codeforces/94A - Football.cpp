#include<stdio.h>

main()
{
    char x,last='2';
    int c=0;
    while(1)
    {
        scanf("%c",&x);
        if(x=='\n')
        {
            break;
        }
        else if(x==last)
        {
            c++;
        }
        else
        {
            c=1;
        }
        if(c==7)
        {
            break;
        }
        last=x;
    }
    if(c<7)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
}
