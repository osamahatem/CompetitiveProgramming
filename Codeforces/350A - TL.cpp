#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n,m,i,x,maxi=0,mini=100,ans;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        maxi=max(maxi,x);
        mini=min(mini,x);
    }
    ans=max(maxi,2*mini);
    mini=100;
    for(i=0;i<m;i++){
        scanf("%d",&x);
        mini=min(mini,x);
    }
    if(ans<mini)
        printf("%d\n",ans);
    else
        printf("-1\n");
	return 0;
}
