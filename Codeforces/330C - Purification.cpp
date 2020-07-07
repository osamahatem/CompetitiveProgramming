#include<cstdio>

int n;
bool flag[105][105];

bool isvalid(int i,int j){
    int c;
    for(c=0;c<n;c++)
        if(!flag[i][c] || !flag[c][j])
            return true;
    return false;
}

void pure(int i,int j){
    int c;
    for(c=0;c<n;c++){
        flag[i][c]=1;
        flag[c][j]=1;
    }
}

int main(){
    int i,j;
    char grid[105][105];
    bool reach[105];
    scanf("%d ",&n);
    for(i=0;i<n;i++){
        reach[i]=0;
        gets(grid[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            flag[i][j]=0;
            if(grid[i][j]=='.'){
                reach[i]=1;
                reach[j]=1;
            }
        }
    }
    for(i=0;i<n;i++){
        if(!reach[i]){
            printf("-1\n");
            return 0;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(grid[i][j]=='.' && isvalid(i,j)){
                printf("%d %d\n",i+1,j+1);
                pure(i,j);
            }
        }
    }
    return 0;
}
