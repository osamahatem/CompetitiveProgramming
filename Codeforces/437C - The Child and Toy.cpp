#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,val[1005],x,y,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&val[i]);
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        ans+=min(val[x],val[y]);
    }
    printf("%d\n",ans);
    return 0;
}
