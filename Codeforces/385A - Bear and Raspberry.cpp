#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int i,n,c,last,x,ans=0;
    scanf("%d%d%d",&n,&c,&last);
    for(i=1;i<n;i++){
        scanf("%d",&x);
        ans=max(ans,last-x-c);
        last=x;
    }
    printf("%d\n",ans);
}
