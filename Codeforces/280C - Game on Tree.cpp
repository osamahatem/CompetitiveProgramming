#include<bits/stdc++.h>

using namespace std;

#define EPS 1e-9

int n;
vector<int> adj[100005];
bool vis[100005];

double solve(int n,int d){
    if(vis[n])
        return 0.0;
    vis[n]=1;
    double ret=0.0;
    for(int i=0;i<adj[n].size();i++)
        ret+=solve(adj[n][i],d+1);
    return ret+1.0/d;
}

int main(){
    int a,b;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    printf("%.9lf\n",solve(1,1));
    return 0;
}
