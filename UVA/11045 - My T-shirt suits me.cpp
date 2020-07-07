#include<bits/stdc++.h>

using namespace std;

map<string,int> sizes;
vector<int> E[50];
int cap[50][50];
bool vis[50];

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
    int next[50],ans=0,temp;
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
    sizes["XS"]=1,sizes["S"]=2,sizes["M"]=3,sizes["L"]=4,sizes["XL"]=5,sizes["XXL"]=6;
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<50;i++)
            E[i].clear();
        int N,M,cur=7;
        char arr[5];
        scanf("%d%d",&N,&M);
        N/=6;
        for(int i=1;i<=6;i++){
            E[0].push_back(i);
            cap[0][i]=N;
            E[i].push_back(0);
            cap[i][0]=0;
        }
        for(int i=0;i<M;i++){
            scanf("%s",arr);
            E[sizes[arr]].push_back(cur);
            cap[sizes[arr]][cur]=1;
            E[cur].push_back(sizes[arr]);
            cap[cur][sizes[arr]]=0;
            scanf("%s",arr);
            E[sizes[arr]].push_back(cur);
            cap[sizes[arr]][cur]=1;
            E[cur].push_back(sizes[arr]);
            cap[cur][sizes[arr]]=0;
            cur++;
        }
        for(int i=7;i<cur;i++){
            E[i].push_back(cur);
            cap[i][cur]=1;
            E[cur].push_back(i);
            cap[cur][i]=0;
        }
        int ans=maxFlow(0,cur);
        if(ans==M)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
