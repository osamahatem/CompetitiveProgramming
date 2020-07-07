#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int n;
long long dp[2005][2005];

long long solve(int k,int cur){
    if(k==0)
        return 1;
    long long &ret=dp[k][cur];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=1;i<=n/cur;i++){
        ret+=solve(k-1,cur*i);
        ret%=MOD;
    }
    return ret;
}

int main(){
    memset(dp,-1,sizeof dp);
    int k;
    scanf("%d%d",&n,&k);
    printf("%I64d\n",solve(k,1));
    return 0;
}
