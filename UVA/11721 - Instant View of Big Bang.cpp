#include<bits/stdc++.h>

using namespace std;

int n,id=0,inQ[1001],head[1001],next[2001],to[2001],cost[2001],dist[2001],last;
vector<int> res;
bool cycle[1001],vis[1001];

void addEdge(int f,int t,int c){
    next[last]=head[f];
    to[last]=t;
    cost[last]=c;
    head[f]=last++;
    return;
}

void bellman(){
    id++;
    memset(dist,0,sizeof dist);
    memset(cycle,0,sizeof cycle);
    memset(vis,0,sizeof vis);
    queue<int> Q;
    for(int i=0;i<n;i++)
        Q.push(i),inQ[i]=id;
    for(int i=0;i<n;i++){
        int s=Q.size();
        while(s--){
            int cur=Q.front();
            Q.pop();
            inQ[cur]=0;
            for(int j=head[cur];j!=-1;j=next[j]){
                int node=to[j];
                if(dist[node]>dist[cur]+cost[j]){
                    dist[node]=dist[cur]+cost[j];
                    if(inQ[node]!=id)
                        Q.push(node),inQ[node]=id;
                }
            }
            if(Q.empty())
                return;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=head[i];j!=-1;j=next[j]){
            int node=to[j];
            if(dist[node]>dist[i]+cost[j])
                cycle[node]=1;
        }
    }
    return;
}

void DFS(int src){
    if(vis[src])
        return;
    vis[src]=1;
    for(int i=head[src];i!=-1;i=next[i])
        DFS(to[i]);
    res.push_back(src);
    return;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++){
        memset(head,-1,sizeof head);
        res.clear();
        last=0;
        int m,f,t,c;
        scanf("%d%d",&n,&m);
        while(m--){
            scanf("%d%d%d",&f,&t,&c);
            addEdge(t,f,c);
        }
        bellman();
        for(int i=0;i<n;i++)
            if(cycle[i])
                DFS(i);
        if(res.size()){
            sort(res.begin(),res.end());
            printf("Case %d:",tc);
            for(int i=0;i<res.size();i++)
                printf(" %d",res[i]);
        }else
            printf("Case %d: impossible",tc);
        printf("\n");
    }
	return 0;
}
