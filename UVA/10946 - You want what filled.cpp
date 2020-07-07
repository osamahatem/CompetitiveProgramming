#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct hole{
    char c;
    int s;
}hole;

int x,y;
char g[55][55];
bool vis[55][55];

int gethole(int i,int j,char l){
    if(i<0 || j<0 || i==x || j==y || vis[i][j] ||l!=g[i][j])
        return 0;
    vis[i][j]=1;
    int ans=1;
    ans+=gethole(i,j+1,l);
    ans+=gethole(i,j-1,l);
    ans+=gethole(i+1,j,l);
    ans+=gethole(i-1,j,l);
    return ans;
}

bool cmp(const hole &a,const hole &b){
    if(a.s!=b.s)
        return a.s>b.s;
    return a.c<b.c;
}

int main(){
    int i,j,p=1;
    vector<hole> ans;
    while(1){
        scanf("%d%d ",&x,&y);
        if(x==0 || y==0)
            break;
        for(i=0;i<x;i++)
            gets(g[i]);
        memset(vis,0,sizeof(vis));
        ans.clear();
        hole temp;
        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                if(!vis[i][j] && g[i][j]!='.'){
                    temp.s=gethole(i,j,g[i][j]);
                    temp.c=g[i][j];
                    ans.push_back(temp);
                }
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        printf("Problem %d:\n",p++);
        for(i=0;i<ans.size();i++)
            printf("%c %d\n",ans[i].c,ans[i].s);
    }
	return 0;
}
