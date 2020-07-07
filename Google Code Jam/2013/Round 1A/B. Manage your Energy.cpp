#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

main()
{
    freopen("B. Manage your Energy.in","r",stdin);
    freopen("B. Manage your Energy.out","w",stdout);
    int t,T,e,r,n,i;
    long long x,energy;
    vector<int> v;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        v.clear();
        energy=0;
        scanf("%d%d%d",&e,&r,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            v.push_back(x);
        }
        sort(v.begin(),v.end(),cmp);
        energy+=e*v[0];
        for(i=1;i<v.size();i++)
        {
            energy+=v[i]*r;
        }
        printf("Case #%d: %lld",t,energy);
        if(t!=T)
        {
            printf("\n");
        }
    }
    return 0;
}
