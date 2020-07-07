#include<stdio.h>
#include<string.h>

main()
{
    int n,len;
    char word[101],first,last;
    scanf("%d",&n);
    for(n;n>=1;n--)
    {
        scanf("%s",&word);
        if(strlen(word)>10)
        {
            first=word[0];
            last=word[strlen(word)-1];
            len=strlen(word)-2;
            printf("%c%d%c\n",first,len,last);
        }
        else
        {
            printf("%s\n",word);
        }
    }
}
