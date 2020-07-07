#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int arr[100000],dp[100000][2];
char m[100000];

int ans(int idx,bool flag){
    if(idx<0)
        return 0;
    int &ret=dp[idx][flag];
    if(ret!=-1)
        return ret;
    int i=0,temp=0;
    if(!flag)
        temp=arr[idx]+ans(idx-1,0);
    else{
        for(;i<m[idx]-'0';i++)
            temp=max(temp,ans(idx-1,0));
        temp=max(temp,arr[idx]*i+ans(idx-1,1));
    }
    return ret=temp;
}

int main(){
    memset(dp,-1,100000*2*4);
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    scanf("%s",m);
    printf("%d\n",ans(n-1,1));
	return 0;
}
