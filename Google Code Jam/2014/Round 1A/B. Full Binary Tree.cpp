#include<bits/stdc++.h>

using namespace std;

vector<int> adj[1005];
bool vis[1005];

int DFS(bool t,int n){
    vis[n]=1;
    if(!t){
        int ret=1;
        for(int i=0;i<adj[n].size();i++)
            if(!vis[adj[n][i]])
                ret+=DFS(t,adj[n][i]);
        return ret;
    }
    int ret=0;
    for(int i=0;i<adj[n].size();i++)
        if(!vis[adj[n][i]])
            ret++;
    if(ret==1){
        for(int i=0;i<adj[n].size();i++)
            if(!vis[adj[n][i]])
                ret+=DFS(0,adj[n][i]);
        return --ret;
    }
    ret=0;
    for(int i=0;i<adj[n].size();i++)
        if(!vis[adj[n][i]])
            ret+=DFS(1,adj[n][i]);
    return ret;
}

int main(){
    freopen("B. Full Binary Tree.in","r",stdin);
    freopen("B. Full Binary Tree.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        for(int i=0;i<=1000;i++)
            adj[i].clear();
        int n,x,y,mini=1005;
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i=1;i<=n;i++){
            if(adj[i].size()==3)
                continue;
            memset(vis,0,sizeof vis);
            mini=min(mini,DFS(1,i));
        }
        printf("Case #%d: %d\n",t,mini);
    }
    return 0;
}
