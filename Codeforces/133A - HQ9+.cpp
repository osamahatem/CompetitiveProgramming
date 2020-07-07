#include<stdio.h>
#include<string.h>

main()
{
    char i,in[100],flag=0;
    gets(in);
    for(i=0;i<strlen(in);i++)
    {
        if(in[i]=='H' || in[i]=='Q' || in[i]=='9')
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
