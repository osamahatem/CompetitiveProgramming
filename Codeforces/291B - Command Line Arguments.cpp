#include<cstdio>
#include<cstring>

using namespace std;

main()
{
    char in[100100];
    int i,x;
    gets(in);
    x=strlen(in);
    for(i=0;i<x;i++)
    {
        if(in[i]==' ')
        {
            continue;
        }
        else if(in[i]=='"')
        {
            printf("<");
            i++;
            while(1)
            {
                if(in[i]=='"' || i==x)
                {
                    printf(">\n");
                    break;
                }
                printf("%c",in[i]);
                i++;
            }
        }
        else
        {
            printf("<");
            while(1)
            {
                if(in[i]==' ' || i==x)
                {
                    printf(">\n");
                    break;
                }
                printf("%c",in[i]);
                i++;
            }
        }
    }
    return 0;
}
