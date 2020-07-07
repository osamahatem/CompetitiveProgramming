#include<cstdio>

int n,joy[3005][3],dp[3005][3];

int main(){
    int i,j;

    scanf("%d",&n);
    for(j=0;j<3;j++)
        for(i=0;i<n;i++){
            scanf("%d",joy[i][j]);
            dp[i][j]=-1;
        }
    return 0;
}
