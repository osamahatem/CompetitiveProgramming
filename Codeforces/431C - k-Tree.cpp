#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int n,k,d;
long long dp[101][2];

long long solve(int left,bool flag){
    if(left==0)
        return flag;
    long long &ret=dp[left][flag];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=1;i<=min(left,k);i++)
        ret=(ret+solve(left-i,flag|(i>=d)))%MOD;
    return ret;
}

int main(){
    memset(dp,-1,sizeof dp);
    scanf("%d%d%d",&n,&k,&d);
    printf("%I64d\n",solve(n,0));
    return 0;
}
