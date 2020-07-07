#include<cstdio>
#include<set>
#include<utility>

using namespace std;

int n,m;
bool vis[1000][1000];
double ans[1000][1000],from_last[1000][1000];
char g[1000][1000];

bool isvalid(int i,int j){
    if(i<0 || i>=n)
        return false;
    if(j<0 || j>=m)
        return false;
    if(vis[i][j])
        return false;
    return true;
}

int main(){
    int i,j,curx,cury,tx,ty;
    set<pair<int,pair<int,int> > > Q;
    pair<int,pair<int,int> > temp;

    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
        scanf("%s",g[i]);

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            ans[i][j]=(double)(1<<30);
            from_last[i][j]=(double)(1<<30);
            vis[i][j]=0;
            if(g[i][j]=='S'){
                ans[i][j]=0;
                from_last[i][j]=0;
                vis[i][j]=1;
            }
            Q.insert(make_pair(ans[i][j],make_pair(i,j)));
            if(g[i][j]=='E'){
                tx=i;
                ty=j;
            }
        }
    }

    while(!Q.empty()){
        temp=*(Q.begin());
        Q.erase(Q.begin());
        curx=temp.second.first;
        cury=temp.second.second;
        vis[curx][cury]=1;

        if(from_last[curx][cury]>5.0)
            continue;

        if(g[curx][cury]=='+')
            from_last[curx][cury]=0;

        for(i=-1;i<=1;i++){
            for(j=-1;j<=1;j++){
                if(i==0 && j==0)
                    continue;

                if(isvalid(curx+i,cury+j)){
                    if(i==0 || j==0){
                        if(ans[curx][cury]+1<ans[curx+i][cury+j] || from_last[curx][cury]+1<from_last[curx+i][cury+j]){
                            Q.erase(make_pair(ans[curx+i][cury+j],make_pair(curx+i,cury+j)));
                            ans[curx+i][cury+j]=ans[curx][cury]+1;
                            Q.insert(make_pair(ans[curx+i][cury+j],make_pair(curx+i,cury+j)));
                            from_last[curx+i][cury+j]=from_last[curx][cury]+1;
                        }
                    }else{
                        if(ans[curx][cury]+1.5<ans[curx+i][cury+j] || from_last[curx][cury]+1.5<from_last[curx+i][cury+j]){
                            Q.erase(make_pair(ans[curx+i][cury+j],make_pair(curx+i,cury+j)));
                            ans[curx+i][cury+j]=ans[curx][cury]+1.5;
                            Q.insert(make_pair(ans[curx+i][cury+j],make_pair(curx+i,cury+j)));
                            from_last[curx+i][cury+j]=from_last[curx][cury]+1.5;
                        }
                    }
                }
            }
        }
    }

    if(ans[tx][ty]<(double)(1<<30) && from_last[tx][ty]<=5.0)
        printf("%.1f\n",ans[tx][ty]);
    else
        printf("IMPOSSIBLE\n");
    return 0;
}
