#include<stdio.h>
#include<string.h>

main()
{
    int c=1,i,temp=0;
    char in[105],last;
    gets(in);
    last=in[0];
    for(i=1;i<strlen(in);i++)
    {
        if(in[i]!=last)
        {
            c++;
            temp=0;
        }
        else
        {
            temp++;
            if(temp==5)
            {
                temp=0;
                c++;
            }
        }
        last=in[i];
    }
    printf("%d\n",c);
}
