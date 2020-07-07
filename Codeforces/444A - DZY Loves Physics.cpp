#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,val[505],u,v,c,maxi_v,maxi_u,maxi_c;
    vector< pair<int,int> > E[505];
    double maxi=0.0;
    bool vis[505];
    scanf("%d%d",&n,&m);
    if(m==0){
        printf("%.15f\n",0);
        return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
        vis[i]=0;
    }
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&c);
        E[u].push_back(make_pair(v,c));
        E[v].push_back(make_pair(u,c));
        if((val[v]+val[u])/(double)c>maxi){
            maxi=(val[v]+val[u])/(double)c;
            maxi_v=v,maxi_u=u,maxi_c=c;
        }
    }
    vis[maxi_v]=vis[maxi_u]=1;
    int num=val[maxi_v]+val[maxi_u],denum=maxi_c;
    set< pair<double, pair<
    for(int i=0;i<E[maxi_v].size();i++)
    return 0;
}
