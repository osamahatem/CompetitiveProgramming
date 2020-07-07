#include<stdio.h>

main()
{
    long n,k,i,j=2;
    scanf("%ld%ld",&n,&k);
    char x[n];
    if(k>n || (n!=1 && k==1))
    {
        printf("-1\n");
        return 0;
    }
    bool t[k],flag=0;
    for(i=0;i<k;i++)
    {
        t[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(n-i+1<k)
        {
            x[i]='a'+j;
            j++;
            k--;
        }
        else if(!flag)
        {
            x[i]='a';
            flag=1;
        }
        else
        {
            x[i]='b';
            flag=0;
        }
    }
    x[i]='\0';
    printf("%s\n",x);
    return 0;
}
