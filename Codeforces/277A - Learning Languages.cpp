#include<bits/stdc++.h>

using namespace std;

vector<int> emp[105],lang[105];
bool vis[105];

void DFS(int n){
    if(vis[n])
        return;
    vis[n]=1;
    for(int i=0;i<emp[n].size();i++){
        int x=emp[n][i];
        for(int j=0;j<lang[x].size();j++)
            DFS(lang[x][j]);
    }
    return;
}

int main(){
    memset(vis,0,sizeof vis);
    int n,m,k,x,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        ans+=k;
        for(int j=0;j<k;j++){
            scanf("%d",&x);
            emp[i].push_back(x);
            lang[x].push_back(i);
        }
    }
    if(ans==0){
        printf("%d\n",n);
        return 0;
    }
    ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i])
            continue;
        ans++;
        DFS(i);
    }
    printf("%d\n",--ans);
    return 0;
}
