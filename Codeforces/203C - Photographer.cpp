#include<stdio.h>
#include<algorithm>

using namespace std;

typedef struct client
{
    int mem;
    int index;
}client;

client photo[100000];

bool comp(const client& x,const client& y)
{
    return x.mem<y.mem;
}

main()
{
    int n,d,a,b,x,y,i,c=0;
    scanf("%d%d%d%d",&n,&d,&a,&b);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        photo[i].mem=x*a+y*b;
        photo[i].index=i;
    }
    sort(photo,photo+n,comp);
    i=0;
    while(d-photo[i].mem>=0 && i<n)
    {
        d-=photo[i].mem;
        i++;
        c++;
    }
    printf("%d\n",c);
    for(i=0;i<c;i++)
    {
        if(i==c-1)
        {
            printf("%d\n",photo[i].index+1);
            return 0;
        }
        printf("%d ",photo[i].index+1);
    }
    return 0;
}
