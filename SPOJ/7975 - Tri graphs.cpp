#include<cstdio>
#include<algorithm>

using namespace std;

int n,grid[100000][3],memo[100000][3];

int getmin(int i,int j){
    if(j==-1 || j==3 || i==n)
        return 1000000000;
    if(j==1 && i==n-1)
        return grid[i][j];
    if(memo[i][j])
        return grid[i][j]+memo[i][j];
    memo[i][j]=1000000000;
    memo[i][j]=min(memo[i][j],getmin(i,j+1));
    memo[i][j]=min(memo[i][j],getmin(i+1,j+1));
    memo[i][j]=min(memo[i][j],getmin(i+1,j));
    memo[i][j]=min(memo[i][j],getmin(i+1,j-1));
    return grid[i][j]+memo[i][j];
}

int main(){
    int t=1;
    while(1){
        scanf("%d",&n);
        if(n==0)
            break;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                scanf("%d",&grid[i][j]);
                memo[i][j]=0;
            }
        }
        printf("%d. %d\n",t++,getmin(0,1));
    }
    return 0;
}
