#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

vector<int> arc[100001];
bool vis[100002];

int check(int a,int b){
    int i,j;
    for(i=0;i<arc[a].size();i++){
        if(arc[a][i]==b)
            continue;
        for(j=0;j<arc[b].size();j++){
            if(arc[a][i]==arc[b][j] && !vis[arc[a][i]]){
                vis[arc[a][i]]=1;
                return arc[b][j];
            }
        }
    }
    return -1;
}

int get_common(int a,int b){
    int i,j,ret=0;
    for(i=0;i<arc[a].size();i++){
        if(arc[a][i]==b)
            continue;
        for(j=0;j<arc[b].size();j++){
            if(arc[a][i]==arc[b][j])
                ret++;
        }
    }
    return ret;
}

int main(){
    int n,i,j,a,b,next;
    vector<int> ans,temp;
    memset(vis,0,sizeof vis);
    scanf("%d",&n);
    for(i=0;i<2*n;i++){
        scanf("%d%d",&a,&b);
        arc[a].push_back(b);
        arc[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        if(arc[i].size()!=4){
            printf("-1\n");
            return 0;
        }
    }
    vis[1]=1;
    for(i=0;i<arc[1].size();i++){
        next=get_common(1,arc[1][i]);
        if(next>=2)
            temp.push_back(arc[1][i]);
    }
    ans.push_back(temp[0]);
    vis[temp[0]]=1;
    ans.push_back(1);
    ans.push_back(temp[1]);
    vis[temp[1]]=1;
    while(ans.size()<n){
        next=check(ans[ans.size()-1],ans[ans.size()-2]);
        if(next==-1){
            printf("-1\n");
            return 0;
        }
        ans.push_back(next);
    }
    for(i=0;i<n;i++){
        if(i>0)
            printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}
