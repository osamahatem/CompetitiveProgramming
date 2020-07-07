#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,l,r,t,arr[100005];
    long long ans[2][100005];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    ans[0][0]=ans[1][0]=0;
    for(int i=0;i<n;i++)
        ans[0][i+1]=ans[0][i]+arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
        ans[1][i+1]=ans[1][i]+arr[i];
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&t,&l,&r);
        t--,l--;
        printf("%I64d\n",ans[t][r]-ans[t][l]);
    }
    return 0;
}
