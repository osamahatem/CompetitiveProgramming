#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct frnd{int f,idx;};

bool cmp(const frnd &a,const frnd &b){
    return a.f<b.f;
}

int n,v,income[405],dp[405][405],dp2[405][405];
vector<frnd> friends[405];

int solve(int idx,int last){
    if(idx==n)
        return 0;
    int &ret=dp[idx][last];
    if(ret!=-1)
        return ret;
    int cur=income[idx]+last-v,j=0,temp;
    ret=solve(idx+1,min(cur,income[idx]));
    dp2[idx][last]=0;
    while(j<friends[idx].size() && cur>=friends[idx][j].f){
        cur-=friends[idx][j].f;
        temp=j+1+solve(idx+1,min(income[idx],cur));
        if(temp>ret){
            ret=temp;
            dp2[idx][last]=j+1;
        }
        j++;
    }
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(dp,-1,sizeof dp);
    memset(dp2,-1,sizeof dp2);
    int i,m,l,r,f,j;
    frnd temp;
    scanf("%d%d",&n,&v);
    for(i=0;i<n;i++)
        scanf("%d",&income[i]);
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&l,&r,&f);
        l--;
        r--;
        temp.idx=i+1;
        temp.f=f;
        for(j=l;j<=r;j++)
            friends[j].push_back(temp);
    }
    for(i=0;i<n;i++)
        sort(friends[i].begin(),friends[i].end(),cmp);
    printf("%d\n",solve(0,0));
    int last=0,cur;
    for(j=0;j<n;j++){
        printf("%d",dp2[j][last]);
        cur=income[j]+last-v;
        for(i=0;i<dp2[j][last];i++){
            cur-=friends[j][i].f;
            printf(" %d",friends[j][i].idx);
        }
        printf("\n");
        last=min(income[j],cur);
    }
    return 0;
}
