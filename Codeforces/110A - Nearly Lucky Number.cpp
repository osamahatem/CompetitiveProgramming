#include<stdio.h>

main()
{
    char x;
    int c=0;
    while(1)
    {
        scanf("%c",&x);
        if(x=='\n')
        {
            break;
        }
        else if(x=='4' || x=='7')
        {
            c++;
        }
    }
    if(c==4 || c==7)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
