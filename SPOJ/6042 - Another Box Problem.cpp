#include<cstdio>
#include<cstring>

#define mod 761238923

int n,dp[101][101];

int get_ways(int idx,int sum){
    if(idx<0){
        if(sum==n)
            return 1;
        return 0;
    }
    if(sum>n-idx)
        return 0;
    int &ret=dp[idx][sum],i;
    if(ret!=-1)
        return ret;
    ret=0;
    ret+=get_ways(idx,sum+1);
    ret+=get_ways(idx-1,sum);
    ret%=mod;
    return ret;
}

int main(){
    while(scanf("%d",&n),n!=0){
        memset(dp,-1,101*101*4);
        printf("%d\n",get_ways(n-1,0));
    }
	return 0;
}
