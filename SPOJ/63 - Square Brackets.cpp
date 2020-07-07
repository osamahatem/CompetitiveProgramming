#include<cstdio>
#include<cstring>

bool open[40];
int dp[40][40],n;

int solve(int i,int cur){
    if(i>2*n && cur==0)
        return 1;
    if(i>2*n || cur<0)
        return 0;
    if(open[i])
        return solve(i+1,cur+1);
    int &ret=dp[i][cur];
    if(ret!=-1)
        return ret;
    ret=solve(i+1,cur+1)+solve(i+1,cur-1);
    return ret;
}

int main(){
    int t,k,i,x;
    scanf("%d",&t);
    while(t--){
        memset(open,0,sizeof open);
        memset(dp,-1,sizeof dp);
        scanf("%d%d",&n,&k);
        for(i=0;i<k;i++){
            scanf("%d",&x);
            open[x]=1;
        }
        printf("%d\n",solve(1,0));
    }
    return 0;
}
