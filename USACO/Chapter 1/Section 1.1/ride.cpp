/*
ID: 19semse1
PROG: ride
LANG: C++
*/

#include<cstdio>

using namespace std;

main()
{
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    char x[10],y[10];
    int a=1,b=1,i;
    gets(x);
    gets(y);
    i=0;
    while(x[i]!='\0')
    {
        a*=x[i]-'A'+1;
        i++;
    }
    i=0;
    while(y[i]!='\0')
    {
        b*=y[i]-'A'+1;
        i++;
    }
    if(a%47==b%47)
    {
        printf("GO\n");
        return 0;
    }
    printf("STAY\n");
    return 0;
}
