#include<bits/stdc++.h>

using namespace std;

int memo[1005];
vector<int> adj[1005];

int solve(int n){
    int &ret=memo[n];
    if(ret!=-1)
        return ret;
    ret=1;
    int c=0;
    for(int i=0;i<adj[n].size();i++){
        int temp=solve(adj[n][i]);
        if(temp>ret)
            ret=temp,c=0;
        if(temp==ret)
            c++;
    }
    if(c>1)
        ret++;
    return ret;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int t,n,m,x,y;
        scanf("%d%d%d",&t,&n,&m);
        memset(memo,-1,sizeof memo);
        for(int i=0;i<=n;i++)
            adj[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            adj[y].push_back(x);
        }
        printf("%d %d\n",t,solve(n));
    }
    return 0;
}
