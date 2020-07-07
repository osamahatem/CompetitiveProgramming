#include<bits/stdc++.h>

using namespace std;

char grid[101][101];
int w,h,dx[]={1,-1,0,0},dy[]={0,0,1,-1},vis[101][101],id=0;

bool valid(int x,int y){
    if(x<0 || y<0 || x==h || y==w)
        return false;
    if(vis[x][y]==id || grid[x][y]=='X')
        return false;
    return true;
}

void BFS(int x,int y){
    ++id;
    queue< pair<int,int> > Q;
    Q.push(make_pair(x,y));
    while(Q.size()){
        x=Q.front().first;
        y=Q.front().second;
        Q.pop();
        if(vis[x][y]==id)
            continue;
        if(grid[x][y]<'D'){
            grid[x][y]++;
            continue;
        }
        vis[x][y]=id;
        for(int i=0;i<4;i++){
            int newx=x+dx[i],newy=y+dy[i];
            if(valid(newx,newy))
                Q.push(make_pair(newx,newy));
        }
    }
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&w,&h);
        for(int i=0;i<h;i++)
            scanf("%s",grid[i]);
        int q,x,y;
        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&x,&y);
            BFS(y,x);
        }
        for(int i=0;i<h;i++)
            printf("%s\n",grid[i]);
    }
	return 0;
}
