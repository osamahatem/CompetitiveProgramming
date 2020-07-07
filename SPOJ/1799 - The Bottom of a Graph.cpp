#include<bits/stdc++.h>

using namespace std;

struct node{
    int idx,root;
    bool vis,inS;
}G[5005];

vector<int> adj[5005],ans;
vector< vector<int> > SCC;
stack<int> S;
int v,idx;

void solve(int n){
    G[n].vis=G[n].inS=1;
    G[n].idx=G[n].root=idx++;
    S.push(n);

    bool flag=1;
    for(int i=0;i<adj[n].size();i++){
        int next=adj[n][i];
        if(next!=n)
            flag=0;
        if(!G[next].vis)
            solve(next),G[n].root=min(G[n].root,G[next].root);
        else if(G[next].inS)
            G[n].root=min(G[n].root,G[next].idx);
    }

    if(G[n].idx==G[n].root){
        vector<int> temp;
        int next;
        do{
            next=S.top();
            G[next].inS=0;
            S.pop();
            temp.push_back(next);
        }while(next!=n);
        SCC.push_back(temp);
    }
    return;
}

int main(){
    int e,a,b;
    while(scanf("%d",&v),v){
        idx=0;
        SCC.clear();
        ans.clear();
        while(!S.empty())
            S.pop();
        for(int i=1;i<=v;i++){
            adj[i].clear();
            G[i].vis=0;
            G[i].inS=0;
        }
        scanf("%d",&e);
        for(int i=0;i<e;i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
        }
        for(int i=1;i<=v;i++)
            if(!G[i].vis)
                solve(i);

        for(int i=0;i<SCC.size();i++){
            bool flag=1;
            for(int j=0;j<SCC[i].size();j++){
                int v=SCC[i][j];
                for(int w=0;w<adj[v].size();w++){
                    if(G[v].root!=G[adj[v][w]].root){
                        flag=0;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
            if(flag)
                for(int j=0;j<SCC[i].size();j++)
                    ans.push_back(SCC[i][j]);
        }

        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(i)
                printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
