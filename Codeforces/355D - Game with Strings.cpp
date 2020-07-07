#include<cstdio>
#include<cstring>
#include<utility>

using namespace std;

int n;
char g[25][25];
pair<int,int> dp[25][25][2];
bool vis[25][25][2];

pair<int,int> play(int i,int j,bool flag){
    if(i==n || j==n)
        return make_pair(-1,-1);
    if(vis[i][j][flag])
        return dp[i][j][flag];
    vis[i][j][flag]=1;
    pair<int,int> &ret=dp[i][j][flag]=make_pair((bool)(g[i][j]=='a'),(bool)(g[i][j]=='b')),first=play(i+1,j,!flag),second=play(i,j+1,!flag);
    if(first.first==-1 && second.first==-1)
        return ret;
    if(first.first==-1){
        ret.first+=second.first;
        ret.second+=second.second;
        return ret;
    }
    if(second.first==-1){
        ret.first+=first.first;
        ret.second+=first.second;
        return ret;
    }
    int a,b;
    if(!flag){
        a=first.second-first.first;
        b=second.second-second.first;
    }else{
        a=first.first-first.second;
        b=second.first-second.second;
    }
    if(a>=b){
        ret.first+=first.first;
        ret.second+=first.second;
        return ret;
    }
    if(b>a){
        ret.first+=second.first;
        ret.second+=second.second;
        return ret;
    }
}

int main(){
    memset(vis,0,25*25*2*sizeof(bool));
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",g[i]);
    pair<int,int> ans=play(0,0,0);
    if(ans.first>ans.second)
        printf("FIRST\n");
    else if(ans.second>ans.first)
        printf("SECOND\n");
    else
        printf("DRAW\n");
	return 0;
}
