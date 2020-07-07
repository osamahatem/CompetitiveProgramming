#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,dp[1000][1000],risk[1000][1000];

int solve(int i,int j){
    if(j<0 || j==m)
        return 1<<30;
    if(i<0)
        return 0;

    int &ret=dp[i][j];
    if(ret!=-1)
        return ret;

    return ret=risk[i][j]+min(solve(i-1,j),min(solve(i-1,j-1),solve(i-1,j+1)));
}

void backtrack(int i,int j){
    if(i==0){
        printf("[%d,%d]",i,j);
        return;
    }
    if(j-1>=0 && dp[i][j]==risk[i][j]+dp[i-1][j-1]){
        backtrack(i-1,j-1);
        printf("[%d,%d]",i,j);
        return;
    }
    if(dp[i][j]==risk[i][j]+dp[i-1][j]){
        backtrack(i-1,j);
        printf("[%d,%d]",i,j);
        return;
    }
    if(j+1<m && dp[i][j]==risk[i][j]+dp[i-1][j+1]){
        backtrack(i-1,j+1);
        printf("[%d,%d]",i,j);
        return;
    }
}

int main(){
    int i,j;

    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            scanf("%d",&risk[i][j]);
            dp[i][j]=-1;
        }

    int ans=solve(n-1,0);
    for(i=1;i<m;i++)
        ans=min(ans,solve(n-1,i));

    printf("Minimum risk path = ");
    for(i=0;i<m;i++){
        if(dp[n-1][i]==ans){
            backtrack(n-1,i);
            break;
        }
    }
    printf("\nRisks along the path = %d\n",ans);
    return 0;
}
