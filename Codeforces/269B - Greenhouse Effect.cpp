#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,a[5005],dp[5005],ans=1;
    scanf("%d%*d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%*lf",&a[i]);

    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++)
            dp[i]=max(dp[i],(a[j]<=a[i])*dp[j]+1);
    }

    for(int i=0;i<n;i++)
        ans=max(ans,dp[i]);
    printf("%d\n",n-ans);
    return 0;
}
