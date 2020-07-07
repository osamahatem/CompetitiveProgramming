#include<bits/stdc++.h>

using namespace std;

int m,n,p,q;

struct cell{
    int x,y;

    cell(int x,int y) : x(x),y(y) {}

    const bool operator == (const cell &a) const{
        return x==a.x && y==a.y;
    }
};

struct step{
    cell c;
    int dist;

    step(cell c,int dist) : c(c),dist(dist) {}
};

bool valid(int x,int y){
    return x>0 && y>0 && x<=m && y<=n;
}

int BFS(cell source,cell target){
    bool vis[105][105];
    memset(vis,0,sizeof vis);
    queue<step> Q;
    Q.push(step(source,0));
    while(Q.size()){
        step cur=Q.front();
        Q.pop();
        if(cur.c==target)
            return cur.dist;
        if(vis[cur.c.x][cur.c.y])
            continue;
        vis[cur.c.x][cur.c.y]=1;
        for(int i=-q;i<=q;i+=2*q){
            for(int j=-p;j<=p;j+=2*p){
                int new_x=cur.c.x+i,new_y=cur.c.y+j;
                if(valid(new_x,new_y) && !vis[new_x][new_y])
                    Q.push(step(cell(new_x,new_y),cur.dist+1));
                new_x=cur.c.x+j,new_y=cur.c.y+i;
                if(valid(new_x,new_y) && !vis[new_x][new_y])
                    Q.push(step(cell(new_x,new_y),cur.dist+1));
            }
        }
    }
    return -1;
}

int main(){
    int x1,y1,x2,y2;
    cin>>m>>n>>p>>q>>x1>>y1>>x2>>y2;
    cell source(x1,y1),target(x2,y2);
    cout<<BFS(source,target)<<endl;
    return 0;
}
