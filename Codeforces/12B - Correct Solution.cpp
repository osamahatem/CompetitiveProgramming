#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>

using namespace std;

main()
{
    char x[15],y[15],temp;
    int a,b,l,m,i;
    scanf("%s%s",x,y);
    a=atoi(y);
    l=strlen(x);
    m=strlen(y);
    sort(x,x+l);
    for(i=0;i<l;i++)
    {
        if(x[i]!='0')
        {
            temp=x[i];
            x[i]=x[0];
            x[0]=temp;
            break;
        }
    }
    b=atoi(x);
    if(l!=m)
    {
        printf("WRONG_ANSWER\n");
    }
    else if(a==b)
    {
        printf("OK\n");
    }
    else
    {
        printf("WRONG_ANSWER\n");
    }
    return 0;
}
