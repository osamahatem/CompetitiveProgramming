#include<bits/stdc++.h>

using namespace std;

int a,b,k;
long long dp[31][2][2][2];

long long solve(int idx,bool fa,bool fb,bool fk){
    if(idx<0)
        return 1;
    long long &ret=dp[idx][fa][fb][fk];
    if(ret!=-1)
        return ret;
    ret=0;
    if((fk || (k&(1<<idx))) && (fa || (a&(1<<idx))) && (fb || (b&(1<<idx))))
        ret+=solve(idx-1,fa,fb,fk);
    ret+=solve(idx-1,fa || (a&(1<<idx)),fb || (b&(1<<idx)),fk || (k&(1<<idx)));
    if(fa || (a&(1<<idx)))
        ret+=solve(idx-1,fa,fb || (b&(1<<idx)),fk || (k&(1<<idx)));
    if(fb || (b&(1<<idx)))
        ret+=solve(idx-1,fa || (a&(1<<idx)),fb,fk || (k&(1<<idx)));
    return ret;
}

int main(){
    freopen("B. New Lottery Game.in","r",stdin);
    freopen("B. New Lottery Game.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(dp,-1,sizeof dp);
        scanf("%d%d%d",&a,&b,&k);
        a--,b--,k--;
        printf("Case #%d: %lld\n",t,solve(30,0,0,0));
    }
    return 0;
}
