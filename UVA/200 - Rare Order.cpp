#include<bits/stdc++.h>

using namespace std;

int last=0,head[26],next[650],to[650];
deque<int> res;
bool vis[26];

void topo(int src){
    if(vis[src])
        return;
    vis[src]=1;
    for(int i=head[src];i!=-1;i=next[i])
        topo(to[i]);
    res.push_front(src);
    return;
}

void addEdge(int f,int t){
    next[last]=head[f];
    to[last]=t;
    head[f]=last++;
    return;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    memset(head,-1,sizeof head);
    memset(vis,1,sizeof vis);
    string prev="",cur;
    while(cin>>cur,cur!="#"){
        int i;
        for(i=0;i<min(cur.size(),prev.size()) && cur[i]==prev[i];i++);
        if(i<min(cur.size(),prev.size())){
            addEdge(prev[i]-'A',cur[i]-'A');
            vis[prev[i]-'A']=0;
            vis[cur[i]-'A']=0;
        }
        prev=cur;
    }
    for(int i=0;i<26;i++)
        topo(i);
    for(int i=0;i<res.size();i++)
        printf("%c",res[i]+'A');
    printf("\n");
	return 0;
}
