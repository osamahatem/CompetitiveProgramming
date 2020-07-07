#include<cstdio>
#include<cstring>

int dp[1000001][3];

int get_ways(int i,int dif){
    if(i<0)
        return 0;
    if(i==0){
        if(dif==0 || dif==2)
            return 1;
        return 0;
    }
    int &ret=dp[i][dif];
    if(ret!=-1)
        return ret;
    ret=0;
    if(dif==0){
        ret+=get_ways(i-2,2);
        ret+=get_ways(i-1,0);
        ret+=2*get_ways(i-2,1);
    }
    if(dif==1){
        ret+=get_ways(i-1,0);
        ret+=get_ways(i-1,1);
    }
    if(dif==2){
        ret+=get_ways(i,0);
    }
    ret%=10000;
    return ret;
}

int main(){
    memset(dp,-1,1000001*3*4);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,ans;
        scanf("%d",&n);
        ans=get_ways(n,0);
        printf("%d\n",ans);
    }
	return 0;
}
