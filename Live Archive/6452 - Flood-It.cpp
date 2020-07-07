#include<cstdio>
#include<set>
#include<queue>
#include<utility>

using namespace std;

int n,g[20][20];
bool vis[20][20];

bool valid(int x,int y,int c){
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    if(vis[x][y])
        return false;
    if(g[x][y]!=c)
        return false;
    return true;
}

int main(){
    int t,i,j,c,maxi,maxi_ind,steps,cnt[6];
    set<pair<int,int> > col[6],so_far;
    set<pair<int,int> >::iterator it;
    queue<pair<int,int> > Q;
    pair<int,int> temp;
    scanf("%d",&t);

    while(t--){
        steps=0;
        for(i=0;i<6;i++)
            cnt[i]=0;
        so_far.clear();
        so_far.insert(make_pair(0,0));
        Q.push(make_pair(0,0));
        for(i=0;i<20;i++)
            for(j=0;j<20;j++)
                vis[i][j]=0;

        scanf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%1d",&g[i][j]);

        while(!Q.empty()){
            temp=Q.front();
            Q.pop();
            vis[temp.first][temp.second]=1;
            for(i=-1;i<=1;i++){
                for(j=-1;j<=1;j++){
                    if(i==0 && j==0)
                        continue;
                    if(i==0 || j==0)
                        if(valid(temp.first+i,temp.second+j,g[0][0])){
                            Q.push(make_pair(temp.first+i,temp.second+j));
                            so_far.insert(make_pair(temp.first+i,temp.second+j));
                        }
                }
            }
        }

        while(so_far.size()<n*n){
            for(i=0;i<6;i++)
                col[i].clear();

            for(c=1;c<=6;c++){
                for(i=0;i<20;i++)
                    for(j=0;j<20;j++)
                        vis[i][j]=0;

                for(it=so_far.begin();it!=so_far.end();it++){
                    Q.push(*it);
                    vis[(*it).first][(*it).second]=1;
                }

                while(!Q.empty()){
                    temp=Q.front();
                    Q.pop();
                    vis[temp.first][temp.second]=1;
                    for(i=-1;i<=1;i++){
                        for(j=-1;j<=1;j++){
                            if(i==0 && j==0)
                                continue;
                            if(i==0 || j==0)
                                if(valid(temp.first+i,temp.second+j,c)){
                                    Q.push(make_pair(temp.first+i,temp.second+j));
                                    col[c-1].insert(make_pair(temp.first+i,temp.second+j));
                                }
                        }
                    }
                }
            }

            maxi=-1,maxi_ind=-1;
            for(i=0;i<6;i++){
                if((int)col[i].size()>maxi){
                    maxi=col[i].size();
                    maxi_ind=i;
                }
            }

            steps++;
            cnt[maxi_ind]++;
            for(it=col[maxi_ind].begin();it!=col[maxi_ind].end();it++)
                so_far.insert(*it);
        }

        printf("%d\n",steps);
        for(i=0;i<6;i++){
            if(i>0)
                printf(" ");
            printf("%d",cnt[i]);
        }
        printf("\n");
    }
    return 0;
}
