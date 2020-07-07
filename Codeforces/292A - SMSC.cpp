#include<cstdio>

main()
{
    int n,i;
    long long tl=1,q=0,maxi=0;
    scanf("%d",&n);
    long long t[n],c[n];
    for(i=0;i<n;i++)
    {
        scanf("%I64d%I64d",&t[i],&c[i]);
    }
    i=0;
    while(i<n)
    {
        if(tl==t[i])
        {
            tl++;
            if(q==0)
            {
                q+=c[i];
                if(maxi<q)
                {
                    maxi=q;
                }
            }
            else
            {
                q+=c[i]-1;
                if(maxi<q)
                {
                    maxi=q;
                }
            }
            i++;
        }
        else
        {
            tl++;
            if(q>0)
            {
                q--;
            }
        }
    }
    tl+=q-1;
    printf("%I64d %I64d\n",tl,maxi);
}
