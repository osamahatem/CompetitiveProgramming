#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<utility>

using namespace std;

int x1,y1;
bool memo[8][8];
queue<pair<int,pair<int,int> > > q;

int BFS(){
    int ans=0;
    bool flag=0;
    while(q.size()){
        for(int x=-2;x<=2;x++){
            for(int y=-2;y<=2;y++){
                if(abs(x)==abs(y) || x==0 || y==0)
                    continue;
                int tx=q.front().second.first+x;
                int ty=q.front().second.second+y;
                if(tx<0 || tx>7 || ty<0 || ty>7)
                    continue;
                if(memo[tx][ty])
                    continue;
                if(tx==x1 && ty==y1){
                    ans=q.front().first+1;
                    flag=1;
                    break;
                }
                memo[tx][ty]=1;
                q.push(make_pair(q.front().first+1,make_pair(tx,ty)));
            }
            if(flag)
                break;
        }
        if(flag)
            break;
        q.pop();
    }
    while(q.size())
        q.pop();
    return ans;
}

int main(){
    int t;
    char st[3],ed[3];
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",st,ed);
        int x0=st[0]-'a',y0=st[1]-'1';
        x1=ed[0]-'a';
        y1=ed[1]-'1';
        q.push(make_pair(0,make_pair(x0,y0)));
        memset(memo,0,sizeof memo);
        memo[x0][y0]=1;
        printf("%d\n",BFS());
    }
	return 0;
}
