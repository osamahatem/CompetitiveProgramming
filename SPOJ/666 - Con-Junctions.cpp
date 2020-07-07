#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> tree[100015];
int best[100015][2],ways[100015][2];

int get_min(int node,int par,bool flag){
    if(best[node][flag]!=-1)
        return best[node][flag];
    if(tree[node].size()==1 && tree[node][0]==par){
        return best[node][flag]=!flag;
    }
    int mini=123456,sum=0;
    for(int i=0;i<tree[node].size();i++){
        if(tree[node][i]!=par){
            sum+=get_min(tree[node][i],node,1);
        }
    }
    sum++;
    mini=min(mini,sum);
    if(flag){
        sum=0;
        for(int i=0;i<tree[node].size();i++){
            if(tree[node][i]!=par){
                sum+=get_min(tree[node][i],node,0);
            }
        }
        mini=min(mini,sum);
    }
    return best[node][flag]=mini;
}

int get_ways(int node,int par,int flag){
    if(tree[node].size()==1 && tree[node][0]==par){
        if(best[node][flag]==0 && flag==0)
            return 0;
        return 1;
    }
    if(ways[node][flag]!=-1)
        return ways[node][flag];
    int sum=0,i,ans1=1;
    for(i=0;i<tree[node].size();i++){
        if(tree[node][i]!=par){
            sum+=best[tree[node][i]][1];
        }
    }
    if(sum+1==best[node][flag]){
        for(i=0;i<tree[node].size();i++){
            if(tree[node][i]!=par){
                ans1*=get_ways(tree[node][i],node,1);
                ans1%=10007;
            }
        }
    }else
        ans1=0;
    if(flag){
        int ans2=1;
        sum=0;
        for(i=0;i<tree[node].size();i++){
            if(tree[node][i]!=par){
                sum+=best[tree[node][i]][0];
            }
        }
        if(sum==best[node][flag]){
            for(i=0;i<tree[node].size();i++){
                if(tree[node][i]!=par){
                    ans2*=get_ways(tree[node][i],node,0);
                    ans2%=10007;
                }
            }
        }else
            ans2=0;
        ans1+=ans2;
    }
    return ways[node][flag]=ans1%10007;
}

int main(){
    int t,n,u,v,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<=n;i++){
            tree[i].clear();
            best[i][0]=-1;
            best[i][1]=-1;
            ways[i][0]=-1;
            ways[i][1]=-1;
        }
        for(i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int mini=get_min(1,0,1);
        int num=get_ways(1,0,1);
        printf("%d %d\n",mini,num);
    }
	return 0;
}
