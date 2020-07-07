#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

#define pi acos(-1.0)

int main(){
    int t,n,x1,y1,x2,y2;
    double ans,add;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=0;
        while(n--){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            add=fabs(atan2(y1,x1)-atan2(y2,x2));
            add=min(add,2*pi-add);
            ans+=add/(2*pi);
        }
        printf("%.5lf\n",ans);
    }
    return 0;
}
