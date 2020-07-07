#include<cstdio>
#include<cstring>

#define mod 1000000007

long long fac[505],dp[500];

int main(){
    int n,i,arr[505];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr[i],arr[i]+n);
    fac[0]=1;
    for(i=1;i<=n;i++){
        fac[i]=fac[i-1]*i;
        fac[i]%=mod;
    }
    return 0;
}
