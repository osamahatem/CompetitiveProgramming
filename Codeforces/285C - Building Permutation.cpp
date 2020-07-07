#include<bits/stdc++.h>

using namespace std;

main()
{
    int n,in[300005];
    long long ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d",&in[i]);
    sort(in,in+n);
    for(int i=0;i<n;i++)
        ans+=abs(i+1-in[i]);
    printf("%I64d\n",ans);
}
