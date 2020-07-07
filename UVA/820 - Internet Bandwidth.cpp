#include<bits/stdc++.h>

using namespace std;

vector<int> E[105];
int cap[105][105];
bool vis[105];

int getPath(int s,int &t,int next[]){
    if(vis[s])
        return 0;
    if(s==t)
        return 1<<30;
    vis[s]=1;
    int ret=0;
    for(int i=0;i<E[s].size();i++){
        if(cap[s][E[s][i]])
            ret=getPath(E[s][i],t,next);
        if(ret){
            ret=min(ret,cap[s][E[s][i]]);
            next[s]=E[s][i];
            break;
        }
    }
    return ret;
}

int maxFlow(int s,int t){
    int next[105],ans=0,temp;
    while(1){
        memset(vis,0,sizeof vis);
        temp=getPath(s,t,next);
        if(!temp)
            break;
        ans+=temp;
        for(int i=s;i!=t;i=next[i]){
            cap[i][next[i]]-=temp;
            cap[next[i]][i]+=temp;
        }
    }
    return ans;
}

int main(){
    int n,T=1;
    while(scanf("%d",&n),n){
        memset(cap,0,sizeof cap);
        for(int i=1;i<=n;i++)
            E[i].clear();
        int s,t,c,u,v,b;
        scanf("%d%d%d",&s,&t,&c);
        for(int i=0;i<c;i++){
            scanf("%d%d%d",&u,&v,&b);
            E[u].push_back(v);
            E[v].push_back(u);
            cap[u][v]+=b;
            cap[v][u]+=b;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n",T++,maxFlow(s,t));
    }
    return 0;
}
