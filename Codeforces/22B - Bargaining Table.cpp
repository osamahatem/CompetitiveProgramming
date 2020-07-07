#include<cstdio>

main()
{
    int n,m,i,j,k,l,a,b,p=0,maxi=0;
    bool flag=0;
    scanf("%d%d\n",&n,&m);
    char x[n+5][m+5];
    for(i=0;i<n;i++)
    {
        gets(x[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            for(k=0;k<n-i;k++)
            {
                for(l=0;l<m-j;l++)
                {
                    for(a=k;a<=k+i;a++)
                    {
                        for(b=l;b<=l+j;b++)
                        {
                            if(x[a][b]=='1')
                            {
                                flag=1;
                            }
                        }
                    }
                    p=(i+j+2)*2;
                    if(maxi<p && !flag)
                    {
                        maxi=p;
                    }
                    flag=0;
                }
            }
        }
    }
    printf("%d\n",maxi);
    return 0;
}
