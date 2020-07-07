#include<bits/stdc++.h>

using namespace std;

map<string,int> outposts;
vector< vector< pair<int,int> > > adj;
bool target[101];
int ammo[101],vis[101][202],id=0;

int dijkstra(){
    id++;
    set< pair< pair<int,int>,int > > Q;
    Q.insert(make_pair(make_pair(0,0),0));
    while(Q.size()){
        int cost=(*Q.begin()).first.first;
        int node=(*Q.begin()).first.second;
        int curAmmo=(*Q.begin()).second;
        Q.erase(Q.begin());
        if(vis[node][curAmmo]==id)
            continue;
        if(target[node])
            return cost;
        vis[node][curAmmo]=id;
        curAmmo+=ammo[node];
        ammo[node]=0;
        for(int i=0;i<adj[node].size();i++){
            int next=adj[node][i].second;
            if(vis[next][curAmmo]==id)
                continue;
            int nextCost=adj[node][i].first;
            if(curAmmo>=nextCost)
                Q.insert(make_pair(make_pair(cost+nextCost,next),curAmmo-nextCost));
        }
    }
    return -1;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int t;
    scanf("%d",&t);
    while(t--){
        memset(target,0,sizeof target);
        outposts.clear();
        int n,m,node=0;
        char name[7],tar[4];
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%s%d%s",name,&ammo[i],tar);
            outposts[name]=node++;
            if(tar[0]=='y')
                target[node-1]=1;
        }
        adj.clear();
        adj.resize(n);
        char from[7],to[7];
        int cost;
        for(int i=0;i<m;i++){
            scanf("%s%s%d",from,to,&cost);
            int x=outposts[from];
            int y=outposts[to];
            adj[x].push_back(make_pair(cost,y));
            adj[y].push_back(make_pair(cost,x));
        }
        int ans=dijkstra();
        if(ans==-1)
            printf("No safe path\n");
        else
            printf("%d\n",ans);
    }
	return 0;
}
