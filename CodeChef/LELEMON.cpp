#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(const int &a,const int &b){
    return a>b;
}

int main(){
    int t,i,j,temp,n,m,ans,vis[100],c;
    vector<int> room;
    scanf("%d",&t);
    while(t--){
        ans=0;
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d",&temp);
            vis[temp]++;
        }
        for(i=0;i<n;i++){
            room.clear();
            scanf("%d",&c);
            for(j=0;j<c;j++){
                scanf("%d",&temp);
                room.push_back(temp);
            }
            sort(room.begin(),room.end(),cmp);
            while(vis[i]-- && room.size()>0){
                ans+=room[0];
                room.erase(room.begin());
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
