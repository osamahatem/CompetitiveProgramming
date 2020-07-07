#include<bits/stdc++.h>

using namespace std;

int main(){
    long long dp[30005][5];
    int coins[]={1,5,10,25,50};
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    for(int c=1;c<=30000;c++){
        for(int i=0;i<5 && coins[i]<=c;i++)
            for(int j=0;j<=i;j++)
                dp[c][i]+=dp[c-coins[i]][j];
    }
    int n;
    while(scanf("%d",&n)!=EOF){
        long long ans=0;
        for(int i=0;i<5;i++)
            ans+=dp[n][i];
        if(ans==1)
            printf("There is only 1 way ");
        else
            printf("There are %lld ways ",ans);
        printf("to produce %d cents change.\n",n);
    }
    return 0;
}
