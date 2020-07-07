#include<stdio.h>

main()
{
    int n,s,t,i,p[100000],flag[100000],c=0;
    scanf("%d %d %d",&n,&s,&t);
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        flag[i]=0;
    }
    while(s!=t)
    {
        if(flag[s-1]==1)
        {
            c=-1;
            break;
        }
        else
        {
            flag[s-1]=1;
            s=p[s-1];
            c++;
        }
    }
    printf("%d\n",c);
}
