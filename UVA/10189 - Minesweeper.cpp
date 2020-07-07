#include<cstdio>

bool valid(int i,int j,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m)
        return false;
    return true;
}

char countmines(char grid[105][105],int i,int j,int n,int m){
    int counter=0,x,y;
    for(x=-1;x<=1;x++)
        for(y=-1;y<=1;y++){
            if(x==0 && y==0)
                continue;
            if(valid(i+x,j+y,n,m) && grid[i+x][j+y]=='*')
                counter++;
        }
    return counter+'0';
}

int main(){
    int n,m,i,j,x=1;
    char grid[105][105];
    while(1){
        scanf("%d%d\n",&n,&m);
        if(n==0 && m==0)
            break;
        else if(x!=1)
            printf("\n");
        for(i=0;i<n;i++)
            gets(grid[i]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(grid[i][j]!='*')
                    grid[i][j]=countmines(grid,i,j,n,m);
        printf("Field #%d:\n",x);
        for(i=0;i<n;i++)
            printf("%s\n",grid[i]);
        x++;
    }
    return 0;
}
