#include<cstdio>

int main(){
    int r,c,i,j,ans=0;
    char grid[15][15];
    scanf("%d%d ",&r,&c);
    for(i=0;i<r;i++)
        gets(grid[i]);
    for(i=0;i<r;i++){
        int temp=0;
        for(j=0;j<c;j++){
            if(grid[i][j]=='.'){
                temp++;
                grid[i][j]='x';
            }else if(grid[i][j]=='S'){
                for(int k=0;k<j;k++)
                    grid[i][k]='.';
                temp=0;
                break;
            }
        }
        ans+=temp;
    }
    for(i=0;i<c;i++){
        int temp=0;
        for(j=0;j<r;j++){
            if(grid[j][i]=='.'){
                temp++;
                grid[j][i]='x';
            }else if(grid[j][i]=='S'){
                for(int k=0;k<j;k++)
                    grid[k][i]='.';
                temp=0;
                break;
            }
        }
        ans+=temp;
    }
    printf("%d\n",ans);
    return 0;
}
