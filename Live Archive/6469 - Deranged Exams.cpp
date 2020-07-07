#include<bits/stdc++.h>

using namespace std;

long long dp[17][1<<17];

long long solve(int k,int mask){
    if(k<0)
        return 1;
    long long &ret=dp[k][mask];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=0;i<17;i++){
        if(mask&(1<<i) && i!=k)
            ret+=solve(k-1,mask&(~(1<<i)));
    }
    return ret;
}

int main(){
    int T;
    scanf("%d",&T);
    memset(dp,-1,sizeof dp);
    while(T--){
        int t,n,k;
        scanf("%d%d%d",&t,&n,&k);
        long long ans=solve(k-1,(1<<n)-1);
        for(int i=2;i<=n-k;i++)
            ans*=i;
        printf("%d %lld\n",t,ans);
    }
    return 0;
}
