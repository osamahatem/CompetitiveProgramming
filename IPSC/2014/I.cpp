#include<bits/stdc++.h>

using namespace std;

vector<int> adj[21005];

int solve(int idx,int add,int fromUp){
    int cur=fromUp+add,ret=cur;
    int nextAdd=0;
    while((1<<nextAdd)<adj[idx].size())
        nextAdd++;
    for(int i=0;i<adj[idx].size();i++)
        ret+=solve(adj[idx][i],nextAdd,cur);
    return ret;
}

int main(){
    //freopen("i1.in","r",stdin);
    //freopen("i1.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        for(int i=1;i<=n;i++)
            adj[i].clear();
        for(int i=1;i<n;i++){
            cin>>x;
            adj[x].push_back(i+1);
        }
        cout<<solve(1,0,0)<<endl;
    }
    return 0;
}
