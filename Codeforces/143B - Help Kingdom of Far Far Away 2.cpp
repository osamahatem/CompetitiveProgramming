#include<cstdio>
#include<cstring>

using namespace std;

main()
{
    char x[105];
    gets(x);
    int l,i,c=2,j=0,k;
    bool dec=0;
    l=strlen(x);
    for(i=0;i<l;i++)
    {
        if(x[i]=='.')
        {
            break;
        }
        else if(x[i]>='0' && x[i]<='9')
        {
            j++;
        }
    }
    k=j;
    for(i=0;i<l;i++)
    {
        if(x[i]=='-')
        {
            printf("($");
        }
        else if(x[i]=='.')
        {
            printf(".");
            dec=1;
        }
        else if(!dec)
        {
            if(i==0)
            {
                printf("$");
            }
            if(k%3==0 && k!=j)
            {
                printf(",%c",x[i]);
            }
            else
            {
                printf("%c",x[i]);
            }
            k--;
        }
        else if(c)
        {
            printf("%c",x[i]);
            c--;
        }
        else
        {
            break;
        }
    }
    if(!dec)
    {
        printf(".00");
    }
    else
    {
        for(i=0;i<c;i++)
        {
            printf("0");
        }
    }
    if(x[0]=='-')
    {
        printf(")\n");
    }
    else
    {
        printf("\n");
    }
    return 0;
}
