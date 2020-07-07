#include<cstdio>
#include<cstring>

int val[21],n;
long long memo[10000][21];

long long get(int sum,int idx){
    if(sum>n || idx>20)
        return 0;
    if(memo[sum][idx]!=-1){
        return memo[sum][idx];
    }
    if(sum==n){
        return 1;
    }
    long long ans=0;
    ans+=get(sum,idx+1);
    if(sum+val[idx]<=n)
        ans+=get(sum+val[idx],idx);
    memo[sum][idx]=ans;
    return ans;
}

int main(){
    for(int i=1;i<22;i++)
        val[i-1]=i*i*i;
    while(scanf("%d",&n)!=EOF){
        memset(memo,-1,sizeof(memo));
        printf("%lld\n",get(0,0));
    }
    return 0;
}
