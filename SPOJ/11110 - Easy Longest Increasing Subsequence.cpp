#include<cstdio>
#include<cstring>

using namespace std;

int seq[15],dp[15],n;

int LIS(int idx){
    if(idx>=n)
        return n;
    int &ret=dp[idx];
    if(ret!=-1)
        return ret;
}

int main(){
    int i;
    memset(dp,-1,sizeof dp);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&seq[i]);
    printf("%d\n",LIS(0));
	return 0;
}
