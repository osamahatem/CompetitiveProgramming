#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int c1,c2,c3,c4,n,m,bus=0,trolley=0,ans,x;
    scanf("%d%d%d%d%d%d",&c1,&c2,&c3,&c4,&n,&m);
    while(n--){
        scanf("%d",&x);
        bus+=min(x*c1,c2);
    }
    bus=min(bus,c3);
    while(m--){
        scanf("%d",&x);
        trolley+=min(x*c1,c2);
    }
    trolley=min(trolley,c3);
    ans=bus+trolley;
    ans=min(ans,c4);
    printf("%d\n",ans);
	return 0;
}
