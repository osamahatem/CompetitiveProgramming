#include<stdio.h>
#include<algorithm>

using namespace std;

main()
{
    double tux,foo=0,bar=0,baz=0,quz=1,pur,x,y,z,t;
    scanf("%lf",&tux);
    for(tux;tux>0;tux--)
    {
        scanf("%lf",&pur);
        foo+=pur;
        bar++;
        x=foo*quz;
        y=bar*baz;
        t=max(x,y);
        if(t==x)
        {
            baz=foo;
            quz=bar;
        }
    }
    printf("%lf",baz/quz);
    return 0;
}
