#include<bits/stdc++.h>

using namespace std;

bool vis[100001];
long long val[100001];
vector<int> adj[100001];

pair<long long,long long> solve(int n){
    if(vis[n])
        return make_pair(0,0);
    vis[n]=1;
    pair<long long,long long> ret=make_pair(0,0),temp;
    for(int i=0;i<adj[n].size();i++){
        temp=solve(adj[n][i]);
        ret.first+=temp.first;
        ret.second+=temp.second;
    }
    val[n]+=ret.second;
    ret.second-=val[n];
    ret.first+=abs(val[n]);
    return ret;
}

int main(){
    memset(vis,0,sizeof vis);
    int n,a,b;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        scanf("%I64d",&val[i]);
    printf("%I64d\n",solve(1).first);
    return 0;
}
