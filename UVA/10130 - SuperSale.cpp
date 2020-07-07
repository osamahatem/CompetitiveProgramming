#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int t,n,i,j,g,v[1001],w[1001],m[1001][35],ans;
    scanf("%d",&t);
    while(t--){
        for(i=0;i<=30;i++)
            m[0][i]=0;
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d%d",&v[i],&w[i]);
    for(i=1;i<=n;i++){
            for(j=0;j<=30;j++){
                m[i][j]=m[i-1][j];
                if(w[i]<=j)
                    m[i][j]=max(m[i][j],m[i-1][j-w[i]]+v[i]);
            }
    }
        scanf("%d",&g);
        for(i=0;i<g;i++){
            scanf("%d",&j);
            ans+=m[n][j];
        }
        printf("%d\n",ans);
    }
	return 0;
}
