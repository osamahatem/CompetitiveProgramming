#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,grid[20][20],memo[20][20];

int getmin(int x,int y){
    if(x==n || y==m)
        return 10000;
    if(x==n-1 && y==m-1)
        return grid[x][y];
    if(memo[x][y])
        return grid[x][y]+memo[x][y];
    memo[x][y]=min(getmin(x+1,y),getmin(x,y+1));
    return grid[x][y]+memo[x][y];
}

int main(){
    int x,y,i,j;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    x--;
    y--;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&grid[i][j]);
            memo[i][j]=0;
        }
    }
    int mini=min(getmin(x+1,y),getmin(x,y+1));
    if(mini<=grid[x][y])
        printf("Y %d\n",grid[x][y]-mini);
    else
        printf("N\n");
    return 0;
}
