#include<bits/stdc++.h>

using namespace std;

vector<int> E[1050];
int cap[1050][1050];
bool vis[1050];

int getPath(int s,int &t,stack<int> &path){
    if(vis[s])
        return 0;
    if(s==t)
        return 1<<30;
    vis[s]=1;
    int ret=0;
    for(int i=0;i<E[s].size();i++){
        if(cap[s][E[s][i]])
            ret=getPath(E[s][i],t,path);
        if(ret){
            ret=min(ret,cap[s][E[s][i]]);
            path.push(s);
            break;
        }
    }
    return ret;
}

int maxFlow(int s,int t,int cat[],int ps,int pe){
    stack<int> path;
    int ans=0,temp;
    while(1){
        while(path.size())
            path.pop();
        path.push(t);
        memset(vis,0,sizeof vis);
        temp=getPath(s,t,path);
        if(!temp)
            break;
        ans+=temp;
        int u=path.top(),v;
        path.pop();
        while(path.size()){
            v=path.top();
            if(v>=ps && v<=pe)
                cat[v]=u;
            cap[u][v]-=temp;
            cap[v][u]+=temp;
            u=v;
            path.pop();
        }
    }
    return ans;
}

int main(){
    int c,p;
    while(scanf("%d%d",&c,&p),c){
        int n,sum=0,categories[1050];
        vector<int> problems[21];
        for(int i=0;i<1050;i++){
            E[i].clear();
            categories[i]=0;
        }
        for(int i=1;i<=c;i++){
            scanf("%d",&n);
            sum+=n;
            E[0].push_back(i);
            E[i].push_back(0);
            cap[0][i]=n;
            cap[i][0]=0;
        }
        for(int i=0;i<p;i++){
            E[i+c+1].push_back(c+p+1);
            E[c+p+1].push_back(i+c+1);
            cap[i+c+1][c+p+1]=1;
            cap[c+p+1][i+c+1]=0;
            scanf("%d",&n);
            int x;
            for(int j=0;j<n;j++){
                scanf("%d",&x);
                E[x].push_back(i+c+1);
                E[i+c+1].push_back(x);
                cap[x][i+c+1]=1;
                cap[i+c+1][x]=0;
            }
        }
        int temp=maxFlow(0,c+p+1,categories,c+1,c+p);
        if(temp==sum){
            for(int i=c+1;i<=c+p;i++)
                problems[categories[i]].push_back(i-c);
            printf("1\n");
            for(int i=1;i<=c;i++){
                for(int j=0;j<problems[i].size();j++){
                    if(j)
                        printf(" ");
                    printf("%d",problems[i][j]);
                }
                printf("\n");
            }
        }else
            printf("0\n");
    }
    return 0;
}
