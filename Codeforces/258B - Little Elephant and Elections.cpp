#include<cstdio>
#include<cstring>

#define mod 1000000007

int n,dp[10][2][10],cnt[10],len,target;
char num[10];

int solve(int idx,bool eq,int cur){
    if(idx==len)
        return cur==target;
    int &ret=dp[idx][eq][cur];
    if(ret!=-1)
        return ret;
    ret=0;
    if(eq)
        ret+=solve(idx+1,eq,cur+(num[idx]=='7'||num[idx]=='4'));
    else{
        for(char i=num[idx];i<='9';i++)
            ret+=solve(idx+1,0,cur+(i=='7'||i=='4'));
    }
    for(char i='0';i<num[idx];i++)
        ret+=solve(idx+1,0,cur+(i=='7'||i=='4'));
    return ret;
}

long long powlog(int b,int p){
    if(!p)
        return 1;
    long long ret=powlog(b,p/2);
    ret*=ret;
    ret%=mod;
    if(p%2)
        ret*=b;
    return ret%mod;
}

long long nCr(int n,int r){
    long long ret=1;
    for(int i=n;i>n-r;i--){
        ret*=i;
        ret%=mod;
    }
    for(int i=2;i<=r;i++){
        ret*=powlog(i,mod-2);
        ret%=mod;
    }
    return ret;
}

long long dp2[10][10][7];

long long solve2(int rem,int idx,int num){
    if(num==0 && rem>=0)
        return 1;
    if(rem<0 || idx<0)
        return 0;
    long long &ret=dp2[rem][idx][num];
    if(ret!=-1)
        return ret;
    ret=solve2(rem,idx-1,num);
    for(int i=1;i<=num;i++){
        ret+=nCr(cnt[idx],i)*solve2(rem-i*idx,idx-1,num-i);
        ret%=mod;
    }
    return ret;
}

int main(){
    scanf("%d",&n);
    sprintf(num,"%d",n);
    len=strlen(num);
    for(int i=0;i<10;i++){
        memset(dp,-1,sizeof dp);
        target=i;
        cnt[i]=solve(0,1,0);
    }
    cnt[0]--;
    long long ans=0;
    memset(dp2,-1,sizeof dp2);
    for(int i=1;i<10;i++){
        ans+=cnt[i]*solve2(i-1,i-1,6);
        ans%=mod;
    }
    ans*=720;
    ans%=mod;
    printf("%I64d\n",ans);
    return 0;
}
