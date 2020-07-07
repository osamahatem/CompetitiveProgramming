#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<utility>
#include<map>

using namespace std;

map <pair<int,int>,int> grid;

void moveants(int x,int y){
    int n=grid[make_pair(x,y)]/4;
    if(n==0)
        return;
    grid[make_pair(x,y)]-=n*4;
    grid[make_pair(x,y+1)]+=n;
    grid[make_pair(x,y-1)]+=n;
    grid[make_pair(x+1,y)]+=n;
    grid[make_pair(x-1,y)]+=n;
    moveants(x,y+1);
    moveants(x,y-1);
    moveants(x+1,y);
    moveants(x-1,y);
}

int main(){
    int i,j,n,t,x,y;
    scanf("%d%d",&n,&t);
    grid[make_pair(0,0)]=n;
    moveants(0,0);
    while(t--){
        scanf("%d%d",&x,&y);
        printf("%d\n",grid[make_pair(x,y)]);
    }
    return 0;
}
