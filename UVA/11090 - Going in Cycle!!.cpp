#include<bits/stdc++.h>

using namespace std;

const double EPS=1e-9;

int n,id=0,inQ[51],head[51],next[2501],to[2501],last;
double cost[2501],dist[51];

void addEdge(int f,int t,int c){
    next[last]=head[f];
    cost[last]=c;
    to[last]=t;
    head[f]=last++;
    return;
}

bool bellman(){
    queue<int> Q;
    memset(dist,0,sizeof dist);
    id++;
    for(int i=1;i<=n;i++)
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
        }
        if(Q.empty())
            return true;
    }
    return false;
}

bool valid(double avg){
    for(int i=0;i<last;i++)
        cost[i]-=avg;
    bool ret=bellman();
    for(int i=0;i<last;i++)
        cost[i]+=avg;
    return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++){
        last=0;
        memset(head,-1,sizeof head);
        int m,f,t,c,maxi=0;
        scanf("%d%d",&n,&m);
        while(m--){
            scanf("%d%d%d",&f,&t,&c);
            addEdge(f,t,c);
            maxi=max(maxi,c);
        }
        double st=0.0,size=maxi+1.0;
        for(size/=2;size>EPS;size/=2)
            if(valid(st+size))
                st+=size;
        printf("Case #%d: ",tc);
        if(st>maxi)
            printf("No cycle found.\n");
        else
            printf("%.2f\n",st);
    }
	return 0;
}
