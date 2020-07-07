#include<stdio.h>
#include<string.h>

main()
{
    int i=0,j=0,p=1;
    char s[51],t[51];
    gets(s);
    gets(t);
    for(i=0;i<strlen(t);i++)
    {
        if(t[i]==s[j])
        {
            j++;
            p++;
        }
    }
    printf("%d\n",p);
}
