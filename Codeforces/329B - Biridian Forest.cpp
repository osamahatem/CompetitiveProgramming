#include<bits/stdc++.h>

using namespace std;

char g[1005][1005];
bool vis[1005][1005];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1},R,C;

struct node{
    int r,c,dist;
};

bool valid(int r,int c){
    if(r<0 || c<0 || r>=R || c>=C) return false;
    if(vis[r][c]) return false;
    if(g[r][c]=='T') return false;
    return true;
}

int main(){
    memset(vis,0,sizeof vis);
    int dist=1<<20,ans=0;
    queue<node> Q;
    scanf("%d%d",&R,&C);
    for(int i=0;i<R;i++)
        scanf("%s",g[i]);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(g[i][j]=='E'){
                node temp;
                temp.r=i;
                temp.c=j;
                temp.dist=0;
                Q.push(temp);
            }
        }
    }
    while(!Q.empty()){
        node cur=Q.front();
        Q.pop();
        if(!valid(cur.r,cur.c))
            continue;
        vis[cur.r][cur.c]=1;
        if(g[cur.r][cur.c]=='S')
            dist=cur.dist;
        if(cur.dist>dist)
            break;
        ans+=g[cur.r][cur.c]-'0';
        for(int i=0;i<4;i++){
            node add;
            add.r=cur.r+dx[i];
            add.c=cur.c+dy[i];
            add.dist=cur.dist+1;
            Q.push(add);
        }
    }
    ans+=2*'0'-'S'-'E';
    printf("%d\n",ans);
    return 0;
}
