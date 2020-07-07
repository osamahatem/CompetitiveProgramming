#include<stdio.h>
#include<string.h>

main()
{
    char in[1000];
    gets(in);
    if(in[0]>='a' && in[0]<='z')
    {
        in[0]+='A'-'a';
    }
    printf("%s\n",in);
}
