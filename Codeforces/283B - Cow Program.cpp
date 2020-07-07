#include<bits/stdc++.h>

using namespace std;

int n,arr[200005];
long long ans[200005][2];
bool vis[200005][2];

long long solve(int idx,int inc){
    if(idx<0 || idx>=n)
        return 0;
    if(vis[idx][inc]){
        if(ans[idx][inc]==-1)
            return -1;
        return ans[idx][inc]-idx;
    }
    vis[idx][inc]=1;
    long long ret=solve(idx+arr[idx]*(inc*2-1),!inc);
    if(ret==-1)
        return ans[idx][inc]=ret;
    ans[idx][inc]=ret+idx+arr[idx];
    return ret+arr[idx];
}

int main(){
    memset(ans,-1,sizeof ans);
    vis[0][1]=1;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=1;i<n;i++)
        if(!vis[i][0])
            solve(i,0);
    for(int i=1;i<n;i++)
        printf("%I64d\n",ans[i][0]);
    return 0;
}
