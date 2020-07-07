#include<cstdio>
#include<vector>
#include<string>

using namespace std;

char x[2000010],y[2000010];

main()
{
    int n,i,c1=0,c2=0,com=0;
    scanf("%d\n",&n);
    gets(x);
    gets(y);
    for(i=0;i<2*n;i++)
    {
        if(x[i]=='1')
        {
            c1++;
        }
        if(y[i]=='1')
        {
            c2++;
        }
        if(x[i]=='1' && y[i]=='1')
        {
            com++;
        }
    }
    if(c1>c2)
    {
        printf("First\n");
    }
    else if(c2>=2*c1)
    {
        printf("Second\n");
    }
    else if(c1==c2)
    {
        if(com%2==1)
        {
            printf("First\n");
        }
        else
        {
            printf("Draw\n");
        }
    }
    else
    {
        printf("Draw\n");
    }
    return 0;
}
