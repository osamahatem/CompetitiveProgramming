#include<stdio.h>
#include<algorithm>

using namespace std;

int x[100000],asc[100000];

void swap(int a,int b)
{
    int temp;
    temp=x[a];
    x[a]=x[b];
    x[b]=temp;
}

main()
{
    int n,i,a,b,flaga=0,flagb=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
        asc[i]=x[i];
    }
    if(n==1 || n==2 || (n==3 && x[0]==x[2]))
    {
        printf("-1\n");
        return 0;
    }
    sort(asc,asc+n);
    a=0;
    b=1;
    while(1)
    {
        if(x[a]==x[b])
        {
            a++;
            b++;
            continue;
        }
        if(b==n)
        {
            break;
        }
        swap(a,b);
        for(i=0;i<n;i++)
        {
            if(x[i]!=asc[i])
            {
                flaga=1;
                break;
            }
        }
        for(i=0;i<n;i++)
        {
            if(x[i]!=asc[n-1-i])
            {
                flagb=1;
                break;
            }
        }
        if(flaga && flagb)
        {
            printf("%d %d\n",a+1,b+1);
            return 0;
        }
        swap(a,b);
        a++;
        b++;
    }
    printf("-1\n");
    return 0;
}
