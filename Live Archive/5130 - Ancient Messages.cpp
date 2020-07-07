#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

char hieroglyphs[6]={'W','A','K','J','S','D'},grid[205][205];
int h,w,vis1[205][205],vis2[205][205],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

bool valid(int i,int j){
    if(i<0 || j<0 || i==h || j==w)
        return false;
    return true;
}

void DFS1(int x,int y,int idx){
    if(grid[x][y]=='0')
        return;
    vis1[x][y]=idx;
    int new_x,new_y;
    for(int i=0;i<4;i++){
        new_x=x+dx[i];
        new_y=y+dy[i];
        if(valid(new_x,new_y) && !vis1[new_x][new_y])
            DFS1(new_x,new_y,idx);
    }
    return;
}

int DFS2(int x,int y){
    if(!valid(x,y))
        return 0;
    if(grid[x][y]=='1')
        return vis1[x][y];
    if(vis2[x][y])
        return (1<<30)-1;
    vis2[x][y]=1;
    int ret=(1<<30)-1,new_x,new_y;
    for(int i=0;i<4;i++){
        new_x=x+dx[i];
        new_y=y+dy[i];
        ret&=DFS2(new_x,new_y);
    }
    return ret;
}

int main(){
    int t=1,i,j,x;
    while(1){
        scanf("%d%d",&h,&w);
        if(h==0 && w==0)
            break;

        printf("Case %d: ",t++);
        memset(vis1,0,sizeof vis1);
        memset(vis2,0,sizeof vis2);

        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                scanf("%1x",&x);
                for(int b=0;b<4;b++){
                    grid[i][j*4+3-b]='0'+(bool)(x&(1<<b));
                }
            }
        }
        w*=4;

        int idx=1;
        for(i=0;i<h;i++)
            for(j=0;j<w;j++)
                if(grid[i][j]=='1' && !vis1[i][j])
                    DFS1(i,j,idx++);

        int cnt[205];
        for(i=0;i<idx;i++)
            cnt[i]=0;

        for(i=0;i<h;i++)
            for(j=0;j<w;j++)
                if(grid[i][j]=='0' && !vis2[i][j])
                    cnt[DFS2(i,j)]++;

        char output[205];
        for(i=1;i<idx;i++)
            output[i-1]=hieroglyphs[cnt[i]];
        sort(output,output+idx-1);

        for(i=0;i<idx-1;i++)
            printf("%c",output[i]);
        printf("\n");
    }
    return 0;
}
