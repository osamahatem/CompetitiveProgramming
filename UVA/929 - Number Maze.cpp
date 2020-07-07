#include<bits/stdc++.h>

using namespace std;

int N,M,g[1005][1005],bestCost[1005][1005];
bool vis[1005][1005];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

struct cell{
    int x,y;

    cell(int x,int y) : x(x),y(y) {}

    const bool operator == (const cell &a) const{
        return x==a.x && y==a.y;
    }

    bool isVis(){
        return vis[x][y];
    }

    void visit(){
        vis[x][y]=1;
        return;
    }

    bool isValid(){
        if(x<0 || y<0 || x==N || y==M)
            return false;
        return !isVis();
    }

    int best(){
        return bestCost[x][y];
    }

    int grid(){
        return g[x][y];
    }

    void setBest(int c){
        bestCost[x][y]=c;
    }
};

struct step{
    cell c;
    int cost;

    step(cell c,int cost) : c(c),cost(cost) {}

    const bool operator < (const step &a) const{
        return cost>a.cost;
    }
};

int Dijkstra(){
    priority_queue<step> Q;
    step cur(cell(0,0),g[0][0]);
    cell target(N-1,M-1);
    Q.push(step(cell(0,0),g[0][0]));
    while(Q.size()){
        cur=Q.top();
        Q.pop();
        if(cur.c==target)
            return cur.cost;
        if(cur.c.isVis())
            continue;
        cur.c.visit();
        int new_x,new_y;
        for(int i=0;i<4;i++){
            new_x=cur.c.x+dx[i],new_y=cur.c.y+dy[i];
            cell to(new_x,new_y);
            if(to.isValid() && cur.cost+to.grid()<to.best()){
                step temp(to,cur.cost+to.grid());
                Q.push(temp);
                to.setBest(temp.cost);
            }
        }
    }
    return -1;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                scanf("%d",&g[i][j]);
                vis[i][j]=0;
                bestCost[i][j]=1<<30;
            }
        }
        printf("%d\n",Dijkstra());
    }
    return 0;
}
