#include<bits/stdc++.h>

using namespace std;

int n,head[101],next[101],to[101],cost[101],last,dist[101];
bool inQ[101];

void addEdge(int f,int t,int c){
    next[last]=head[f];
    to[last]=t;
    cost[last]=c;
    head[f]=last++;
}

bool bellman(){
    memset(dist,0,sizeof dist);
    queue<int> Q;
    for(int i=0;i<=n;i++)
        Q.push(i),inQ[i]=1;
    for(int j=0;j<=n;j++){
        int s=Q.size();
        while(s--){
            int cur=Q.front();
            Q.pop();
            inQ[cur]=0;
            for(int i=head[cur];i!=-1;i=next[i]){
                if(dist[to[i]]>dist[cur]+cost[i]){
                    dist[to[i]]=dist[cur]+cost[i];
                    if(!inQ[to[i]])
                        Q.push(to[i]),inQ[to[i]]=1;
                }
            }
        }
        if(Q.empty())
            return true;
    }
    return false;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int m;
    char arr[3];
    while(scanf("%d",&n),n){
        memset(head,-1,sizeof head);
        last=0;
        scanf("%d",&m);
        int a,b,c;
        while(m--){
            scanf("%d%d%s%d",&a,&b,arr,&c);
            b+=a;
            a--;
            if(arr[0]=='g')
                swap(a,b),c*=-1;
            c--;
            addEdge(b,a,c);
        }
        printf("%s\n",bellman() ? "lamentable kingdom" : "successful conspiracy");
    }
	return 0;
}
