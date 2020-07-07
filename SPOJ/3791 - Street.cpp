#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,t,mini[505][505],dp[505][505];

int get_max(int k,int i){
    if(i>=n || k==0)
        return 0;
    int c,&ret=dp[k][i];
    if(ret!=-1)
        return ret;
    ret=get_max(k,i+1);
    for(c=0;c<t,i+c<n;c++){
        ret=max(ret,get_max(k-1,i+c+1)+mini[i][i+c]*(c+1));
    }
    return ret;
}

int main(){
    memset(dp,-1,505*505*4);
    int i,j,h[505],temp,k;
    scanf("%d%d%d",&n,&k,&t);
    for(i=0;i<n;i++)
        scanf("%d",&h[i]);
    for(i=0;i<n;i++){
        temp=h[i];
        for(j=i;j<n;j++){
            mini[i][j]=min(temp,h[j]);
            temp=mini[i][j];
        }
    }
    printf("%d\n",get_max(k,0));
	return 0;
}
