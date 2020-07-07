#include<cstdio>
#include<cstring>

main()
{
    char x[105],y[105],out[105];
    int l,i;
    gets(x);
    gets(y);
    l=strlen(x);
    for(i=0;i<l;i++)
    {
        if(x[i]==y[i])
        {
            out[i]='0';
        }
        else
        {
            out[i]='1';
        }
    }
    out[i]='\0';
    printf("%s\n",out);
    return 0;
}
