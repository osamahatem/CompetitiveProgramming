/*
ID: 19semse1
PROG: friday
LANG: C++
*/

#include<cstdio>

main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int counter[7]={0,0,0,0,0,0,0};
    int y,m,d,n,i=2;
    scanf("%d",&n);
    for(y=1900;y<1900+n;y++)
    {
        if(y%4==0 && y%100!=0)
        {
            days[1]=29;
        }
        else if(y%100==0 && y%400==0)
        {
            days[1]=29;
        }
        else
        {
            days[1]=28;
        }
        for(m=0;m<12;m++)
        {
            for(d=1;d<=days[m];d++)
            {
                if(i==7)
                {
                    i=0;
                }
                if(d==13)
                {
                    counter[i]++;
                }
                i++;
            }
        }
    }
    for(i=0;i<7;i++)
    {
        printf("%d",counter[i]);
        if(i!=6)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
