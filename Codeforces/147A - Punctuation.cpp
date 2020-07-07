#include<stdio.h>
#include<string.h>

main()
{
    char c[10000];
    int i,flag=0;
    gets(c);
    for(i=0;i<strlen(c);i++)
    {
        if(c[i]>='a' && c[i]<='z')
        {
            if(flag==1)
            {
                printf(" %c",c[i]);
                flag=0;
            }
            else
            {
                printf("%c",c[i]);
            }
        }
        else if(c[i]==' ')
        {
            flag=1;
        }
        else
        {
            printf("%c",c[i]);
            flag=1;
        }
    }
    printf("\n");
}
