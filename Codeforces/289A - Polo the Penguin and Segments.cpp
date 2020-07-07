#include<stdio.h>
#include<algorithm>

using namespace std;

main()
{
    long long n,k,i,x=0,sum=0;
    scanf("%I64d%I64d",&n,&k);
    int l[n],r[n];
    for(i=0;i<n;i++)
    {
        scanf("%I64d%I64d",&l[i],&r[i]);
        x+=r[i]-l[i]+1;
    }
    if(x%k==0)
    {
        printf("0\n");
    }
    else
    {
        printf("%I64d\n",k-(x%k));
    }
    return 0;
}
