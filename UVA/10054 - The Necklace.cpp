#include<bits/stdc++.h>

using namespace std;

deque< pair<int,int> > res;
bool vis[2001];
int head[51],next[2001],to[2001],last;

void addEdge(int f,int t){
    next[last]=head[f];
    to[last]=t;
    head[f]=last++;
}

void euler(int src){
    for(int i=head[src];i!=-1;i=next[i]){
        if(vis[i])
            continue;
        vis[i]=1;
        if(i%2)
            vis[i-1]=1;
        else
            vis[i+1]=1;
        euler(to[i]);
        res.push_front(make_pair(src,to[i]));
    }
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int T,deg[51];
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        last=0;
        memset(head,-1,sizeof head);
        memset(vis,0,sizeof vis);
        memset(deg,0,sizeof deg);
        int n,a,b,src;
        scanf("%d",&n);
        while(n--){
            scanf("%d%d",&a,&b);
            deg[a]^=1;
            deg[b]^=1;
            addEdge(a,b);
            addEdge(b,a);
            src=a;
        }
        printf("%sCase #%d\n",t>1 ? "\n" : "",t);
        bool flag=0;
        for(int i=0;i<=50;i++)
            if(deg[i]%2)
                flag=1;
        if(flag){
            printf("some beads may be lost\n");
            continue;
        }
        res.clear();
        euler(src);
        for(int i=0;i<res.size();i++)
            printf("%d %d\n",res[i].first,res[i].second);
    }
	return 0;
}
