#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char num[100010];
int dp[100010],len;
long long bak[100010];

int get_best(int n){
    if(len==n)
        return dp[n]=0;
    int &ret=dp[n];
    if(ret!=-1)
        return ret;
    ret=get_best(n+1);
    if(n+1<len && num[n]-'0'+num[n+1]-'0'==9)
        ret=max(ret,1+get_best(n+2));
    return ret;
}

long long bk_trk(int n){
    if(len==n)
        return 1;
    long long &ret=bak[n],temp;
    if(ret!=-1)
        return ret;
    ret=0;
    if(dp[n+1]==dp[n])
        ret+=bk_trk(n+1);
    if(n+1<len && dp[n+2]+1==dp[n] && num[n]-'0'+num[n+1]-'0'==9)
        ret+=bk_trk(n+2);
    return ret;
}

int main(){
    memset(dp,-1,sizeof dp);
    memset(bak,-1,sizeof bak);
    scanf("%s",num);
    len=strlen(num);
    get_best(0);
    printf("%I64d\n",bk_trk(0));
    return 0;
}
