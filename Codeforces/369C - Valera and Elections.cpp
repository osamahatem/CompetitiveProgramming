#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

struct edge{int tar,t;};

vector<edge> tree[100001];
vector<int> elec;
bool vis[100001];

int DFS(int cur,bool need){
    if(vis[cur])
        return 0;
    int ans=0;
    vis[cur]=1;
    for(int i=0;i<tree[cur].size();i++){
        if(tree[cur][i].t==2)
            ans+=DFS(tree[cur][i].tar,1);
        else
            ans+=DFS(tree[cur][i].tar,0);
    }
    vis[cur]=0;
    if(need && ans==0){
        ans++;
        elec.push_back(cur);
    }
    return ans;
}

int main(){
    memset(vis,0,sizeof vis);
    int n,i,x,y;
    edge temp;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d%d",&x,&y,&temp.t);
        temp.tar=x;
        tree[y].push_back(temp);
        temp.tar=y;
        tree[x].push_back(temp);
    }
    DFS(1,0);
    printf("%d\n",elec.size());
    for(i=0;i<elec.size();i++){
        if(i>0)
            printf(" ");
        printf("%d",elec[i]);
    }
    printf("\n");
    return 0;
}
