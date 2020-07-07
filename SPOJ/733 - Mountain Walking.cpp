#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int n,g[105][105],memo[105][105];
bool vis[105][105];

bool valid(int i,int j){
    if(i<0 || j<0 || i>=n || j>=n || vis[i][j])
        return false;
    return true;
}

int get_min(int i,int j){
    if(i==n-1 && j==n-1)
        return 0;
    int &ret=memo[i][j];
    if(ret!=-1)
        return ret;
    vis[i][j]=1;
    ret=200;
    if(valid(i+1,j))
        ret=min(ret,max(abs(g[i][j]-g[i+1][j]),get_min(i+1,j)));
    if(valid(i-1,j))
        ret=min(ret,max(abs(g[i][j]-g[i-1][j]),get_min(i-1,j)));
    if(valid(i,j+1))
        ret=min(ret,max(abs(g[i][j]-g[i][j+1]),get_min(i,j+1)));
    if(valid(i,j-1))
        ret=min(ret,max(abs(g[i][j]-g[i][j-1]),get_min(i,j-1)));
    return ret;
}

int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            scanf("%d",&g[i][j]);
            memo[i][j]=-1;
            vis[i][j]=0;
        }
    printf("%d\n",get_min(0,0));
	return 0;
}
