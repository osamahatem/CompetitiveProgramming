#include<cstdio>
#include<vector>

using namespace std;

vector<int> adj[100005];
int k,s,step[100005],len[100005];
bool vis[100005];

bool DFS(int n,int l){
    if(vis[n] && l-len[n]>k){
        s=n;
        return true;
    }
    if(vis[n])
        return false;
    vis[n]=1;
    len[n]=l;
    for(int i=0;i<adj[n].size();i++)
        if(DFS(adj[n][i],l+1)){
            step[n]=adj[n][i];
            return true;
        }
    return false;
}

int main(){
    int n,m,i,a,b;
    vector<int> cycle;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1,0);
    a=s;
    do{
        cycle.push_back(a);
        a=step[a];
    }while(a!=s);
    printf("%d\n",cycle.size());
    for(i=0;i<cycle.size();i++){
        if(i>0)
            printf(" ");
        printf("%d",cycle[i]);
    }
    printf("\n");
    return 0;
}
