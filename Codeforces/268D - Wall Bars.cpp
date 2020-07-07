#include<cstdio>
#include<cstring>

#define mod 1000000009

int n,h;
long long dp[1005][35],ans=0;

long long solve(int i,int rem){
    if(i==n)
        return 1;
    if(rem==h)
        return solve(i+1,1);
    long long &ret=dp[i][rem];
    if(ret!=-1)
        return ret;
    ret=3*solve(i+1,rem+1)+solve(i+1,1);
    ret%=mod;
    return ret;
}

int main(){
    scanf("%d%d",&n,&h);
    memset(dp,-1,sizeof dp);
    printf("%I64d\n",solve(0,0));
    return 0;
}
