#include<cstdio>
#include<cstring>

long long dp[5][1005][2][2],n;

long long solve(int r,int idx,bool flag,bool first){
    if(idx==0){
        if(flag && first)
            return 0;
        return (r-flag==4);
    }
    if(r>4)
        return 0;
    long long &ret=dp[r][idx][flag][first];
    if(ret!=-1)
        return ret;
    if(flag)
        return solve(r,idx-1,0,first);
    ret=solve(r+1,idx-1,0,first)+solve(r,idx-1,1,first);
    return ret;
}

int main(){
    int t=1;
    long long ans;
    memset(dp,-1,sizeof dp);
    while(1){
        scanf("%d",&n);
        if(!n)
            break;
        if(n%2)
            ans=0;
        else
            ans=solve(0,n,0,0)+solve(0,n-1,1,1);
        printf("Case %d: %lld\n",t++,ans);
    }
    return 0;
}
