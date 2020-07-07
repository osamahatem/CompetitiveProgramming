#include<cstdio>
#include<cstring>

int n,p,all[55];
double fac[55],dp[55][55][55];

double solve(int idx,int sum,int cur,int len){
    if(sum>p)
        return 0;
    if(idx==n){
        if(sum>p-all[cur])
            return fac[len]*fac[n-1-len]/fac[n]*len;
        else return 0;
    }
    double &ret=dp[idx][sum][len];
    if(ret>-1.0)
        return ret;
    ret=0;
    if(idx==cur)
        return ret=solve(idx+1,sum,cur,len);
    return ret=solve(idx+1,sum,cur,len)+solve(idx+1,sum+all[idx],cur,len+1);
}

void init_fac(){
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i;
    return;
}

int main(){
    int total=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&all[i]),total+=all[i];
    scanf("%d",&p);
    if(total<=p){
        printf("%d\n",n);
        return 0;
    }
    init_fac();
    double ans=0;
    for(int i=0;i<n;i++){
        memset(dp,-1,sizeof dp);
        ans+=solve(0,0,i,0);
    }
    printf("%lf\n",ans);
    return 0;
}
