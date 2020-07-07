#include<bits/stdc++.h>

using namespace std;

char in[1000005];
int len,dp[1000005][2][2];

int solve(int n,bool flag,bool last){
    if(n==len)
        return 0;
    int &ret=dp[n][flag][last];
    if(ret!=-1)
        return ret;
    ret=min((flag!=(in[n]-'0'))+solve(n+1,flag,0),2+solve(n+1,!flag,1));
    return ret;
}

int main(){
    memset(dp,-1,sizeof dp);
    scanf("%s",in);
    len=strlen(in);
    printf("%d\n",solve(0,0,0));
    return 0;
}
