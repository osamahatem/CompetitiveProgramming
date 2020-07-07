#include<cstdio>
#include<cstring>

using namespace std;

main()
{
    char x[205];
    int l,i;
    bool flag=0;
    gets(x);
    l=strlen(x);
    for(i=0;i<l;i++)
    {
        if(x[i]=='W' && x[i+1]=='U' && x[i+2]=='B')
        {
            i+=2;
            if(i==l-1)
            {
                break;
            }
            else if(flag)
            {
                printf(" ");
                flag=0;
                continue;
            }
        }
        else
        {
            printf("%c",x[i]);
            flag=1;
        }
    }
    printf("\n");
    return 0;
}
