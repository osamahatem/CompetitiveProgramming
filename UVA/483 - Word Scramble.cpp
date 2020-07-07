#include<stdio.h>
#include<string.h>

main()
{
    char word[100],x;
    int c;
    while(scanf("%s",&word)!=EOF)
    {
        for(c=strlen(word)-1;c>=0;c--)
        {
            printf("%c",word[c]);
        }
        scanf("%c",&x);
        if(x!='\n')
        {
            printf(" ");
        }
        else if(x=='\n')
        {
            printf("\n");
        }
    }
}
