#include<cstdio>
#include<cstring>

int k,n,m;
char plate[11][11][11];
bool vis[11][11][11];

int fill_plate(int z,int x, int y){
    if(z==k || z<0 || x==n || x<0 || y==m || y<0)
        return 0;
    if(vis[z][x][y])
        return 0;
    if(plate[z][x][y]=='#')
        return 0;
    vis[z][x][y]=1;
    int ret=1;
    ret+=fill_plate(z+1,x,y);
    ret+=fill_plate(z-1,x,y);
    ret+=fill_plate(z,x+1,y);
    ret+=fill_plate(z,x-1,y);
    ret+=fill_plate(z,x,y+1);
    ret+=fill_plate(z,x,y-1);
    return ret;
}

int main(){
    int i,j,x,y;
    scanf("%d%d%d",&k,&n,&m);
    for(i=0;i<k;i++)
        for(j=0;j<n;j++)
            scanf("%s",plate[i][j]);
    scanf("%d%d",&x,&y);
    memset(vis,0,sizeof vis);
    printf("%d\n",fill_plate(0,x-1,y-1));
	return 0;
}
