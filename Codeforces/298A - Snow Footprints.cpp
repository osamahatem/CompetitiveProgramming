#include<cstdio>
#include<cstring>

main()
{
    int n,i,l,s,t,flag=2;
    scanf("%d\n",&n);
    char x[n+5];
    gets(x);
    for(i=0;i<n;i++)
    {
        if(x[i]=='R' && flag==2)
        {
            s=i+1;
            flag=1;
        }
        else if(x[i]=='L' && flag==1)
        {
            t=i;
            flag=3;
        }
        else if(x[i]=='.' && flag==1)
        {
            t=i+1;
            flag=3;
        }
        else if(x[i]=='L' && flag==2)
        {
            t=i;
            flag=0;
        }
        else if(x[i]=='.' && flag==0)
        {
            s=i;
            flag=3;
        }
    }
    printf("%d %d\n",s,t);
    return 0;
}
