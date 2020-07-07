#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,arr[100005];
    long long initial=0,ans;
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=1;i<n;i++)
        initial+=abs(arr[i]-arr[i-1]);
    ans=initial;
    vector<int> adj[100005];
    for(int i=0;i<n;i++){
        if(i>0)
            adj[arr[i]].push_back(arr[i-1]);
        if(i+1<n)
            adj[arr[i]].push_back(arr[i+1]);
    }
    for(int i=1;i<=m;i++){
        if(adj[i].size()==0)
            continue;
        sort(adj[i].begin(),adj[i].end());
        long long a=0,b=0;
        for(int j=0;j<adj[i].size();j++)
            a+=abs(i-adj[i][j]);
        int temp=(adj[i].size()-1)/2;
        temp=adj[i][temp];
        for(int j=0;j<adj[i].size();j++)
            b+=abs(temp-adj[i][j]);
        ans=min(ans,initial-(a-b));
    }
    printf("%I64d\n",ans);
    return 0;
}
