#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

char bitmap[185][185];
int n,m,ans[185][185];
bool vis[185][185];

bool valid(int x,int y){
    if(x<0 || y<0)
        return false;
    if(x==n || y==m)
        return false;
    if(vis[x][y])
        return false;
    return true;
}

void BFS(){
    queue<pair<int,int> > q;
    int tx,ty;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(bitmap[i][j]=='1'){
                q.push(make_pair(i,j));
                ans[i][j]=0;
                vis[i][j]=1;
            }
        }
    }
    while(!q.empty()){
        tx=q.front().first;
        ty=q.front().second;
        q.pop();
        if(valid(tx+1,ty)){
            q.push(make_pair(tx+1,ty));
            ans[tx+1][ty]=min(ans[tx+1][ty],ans[tx][ty]+1);
            vis[tx+1][ty]=1;
        }
        if(valid(tx-1,ty)){
            q.push(make_pair(tx-1,ty));
            ans[tx-1][ty]=min(ans[tx-1][ty],ans[tx][ty]+1);
            vis[tx-1][ty]=1;
        }
        if(valid(tx,ty+1)){
            q.push(make_pair(tx,ty+1));
            ans[tx][ty+1]=min(ans[tx][ty+1],ans[tx][ty]+1);
            vis[tx][ty+1]=1;
        }
        if(valid(tx,ty-1)){
            q.push(make_pair(tx,ty-1));
            ans[tx][ty-1]=min(ans[tx][ty-1],ans[tx][ty]+1);
            vis[tx][ty-1]=1;
        }
    }
    return;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int i,j,sx,sy;
        bool flag=0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%s",bitmap[i]);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                ans[i][j]=400;
                vis[i][j]=0;
            }
        }
        BFS();
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(j>0)
                    printf(" ");
                printf("%d",ans[i][j]);
            }
            printf("\n");
        }
    }
	return 0;
}
