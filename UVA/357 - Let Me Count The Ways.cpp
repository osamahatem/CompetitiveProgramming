#include<bits/stdc++.h>

using namespace std;

int coins[]={1,5,10,25,50};
long long dp[30005][5];

long long solve(int n,int t){
    if(n<0)
        return 0;
    if(!n)
        return 1;

    long long &ret=dp[n][t];
    if(ret!=-1)
        return ret;

    ret=0;
    for(int i=0;i<=t;i++)
        ret+=solve(n-coins[i],i);
    return ret;
}

int main(){
    int n;
    memset(dp,-1,sizeof dp);
    while(scanf("%d",&n)!=EOF){
        long long ans=solve(n,4);
        if(ans==1)
            printf("There is only 1 way ");
        else
            printf("There are %lld ways ",ans);
        printf("to produce %d cents change.\n",n);
    }
    return 0;
}
