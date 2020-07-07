#include<stdio.h>

main()
{
    int i=0,j=0;
    char in[101],hello[6]={'h','e','l','l','o'};
    gets(in);
    while(in[i]!='\0')
    {
        if(in[i]==hello[j])
        {
            j++;
        }
        if(j==5)
        {
            break;
        }
        i++;
    }
    if(j==5)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
