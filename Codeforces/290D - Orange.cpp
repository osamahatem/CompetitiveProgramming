#include<stdio.h>
#include<string.h>

main()
{
    char in[60];
    int x,i,y;
    gets(in);
    scanf("%d",&x);
    y=strlen(in);
    for(i=0;i<y;i++)
    {
        if(in[i]<96)
        {
            in[i]+=32;
        }
    }
    for(i=0;i<y;i++)
    {
        if(in[i]<x+97)
        {
            in[i]-=32;
        }
    }
    printf("%s\n",in);
    return 0;
}
