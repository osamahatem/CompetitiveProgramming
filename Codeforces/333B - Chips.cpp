#include<cstdio>

int n;
bool g[1000][1000];

bool isrowval(int i){
    int j;
    for(j=0;j<n;j++)
        if(g[i][j])
            return false;
    return true;
}

bool iscolval(int i){
    int j;
    for(j=0;j<n;j++)
        if(g[j][i])
            return false;
    return true;
}

int main(){
    int m,i,j,x,y,ans=0;
    bool row[1000],col[1000];
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        row[i]=0;
        col[i]=0;
        for(j=0;j<n;j++)
            g[i][j]=0;
    }
    g[0][0]=1;
    g[0][n-1]=1;
    g[n-1][0]=1;
    g[n-1][n-1]=1;
    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        g[--y][--x]=1;
    }
    for(i=0;i<n;i++){
        if(isrowval(i))
            row[i]=1;
        if(iscolval(i))
            col[i]=1;
    }
    for(i=0;i<n;i++)
        ans+=row[i]+col[i];
    if(row[n/2] && col[n/2] && n%2)
        ans--;
    printf("%d\n",ans);
    return 0;
}
